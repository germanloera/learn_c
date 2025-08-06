#include "studentUI.h"
#include "../../student/database.h"
#include "../../student/student.h"
#include "../utils/frameVisibility.h"
#include "imgui/imgui.h"
#include "imtui/imtui-impl-ncurses.h"
#include <cstddef>
#include <string>

using namespace std;

void StudentFrame::addStudentFrame() {

  // Panel con borde
  if (ImGui::BeginChild("FormPanel", ImVec2(40, 30), true,
                        ImGuiWindowFlags_AlwaysUseWindowPadding)) {

    // Campos numéricos
    ImGui::Text("Info Estudiante");
    ImGui::InputInt("ID", &numero_entero);

    // Campos de texto
    ImGui::Text("Texto");
    ImGui::InputText("Nombre", texto1, sizeof(texto1));
    ImGui::InputText("Tesis/Grado", texto2, sizeof(texto2));

    // Radio buttons
    ImGui::Text("Opciones");
    ImGui::RadioButton("PREGRADO", &radio_selection, 0);
    ImGui::SameLine();
    ImGui::RadioButton("POSTGRADO", &radio_selection, 1);
  }

  // Botón
  if (ImGui::Button("Guardar", ImVec2(-1, 0))) {
    CareerType type = CareerType::PRE;
    if (radio_selection == 1) {
      type = CareerType::POST;
    }
    Student *s = new Student(numero_entero, texto1, type, texto2);
    h->addStudent(s);
  }

  ImGui::EndChild();
}

void StudentFrame::studentListTable() {

  if (showStudentTable) {

    if (ImGui::BeginChild("FormPanel1")) {
      if (ImGui::BeginTable("Estudiantes_registrados", 5)) {

        // Encabezados
        ImGui::TableSetupColumn("Id", ImGuiTableColumnFlags_WidthFixed, 10.0f);
        ImGui::TableSetupColumn("Nombre", ImGuiTableColumnFlags_WidthFixed,
                                10.0f);
        ImGui::TableSetupColumn("Tipo", ImGuiTableColumnFlags_WidthFixed,
                                10.0f);
        ImGui::TableSetupColumn("Carrera", ImGuiTableColumnFlags_WidthFixed,
                                10.0f);
        ImGui::TableSetupColumn("Tesis", ImGuiTableColumnFlags_WidthFixed,
                                10.0f);
        ImGui::TableHeadersRow();

        // Filas de datos

        Student *current = root;

        while (current != NULL) {
          string tipo = "";
          string degree = " - ";
          string thesis = " - ";

          if (current->type == CareerType::PRE) {
            tipo = "PREGRADO";
            degree = current->data.degree;
          } else {
            tipo = "POSTGRADO";
            thesis = current->data.thesis;
          }

          ImGui::TableNextRow();
          ImGui::TableSetColumnIndex(0);
          ImGui::Text("%d", current->id);
          ImGui::TableSetColumnIndex(1);
          ImGui::Text("%s", current->name.c_str());
          ImGui::TableSetColumnIndex(2);

          ImGui::Text("%s", tipo.c_str());
          ImGui::TableSetColumnIndex(3);
          ImGui::Text("%s", degree.c_str());
          ImGui::TableSetColumnIndex(4);
          ImGui::Text("%s", thesis.c_str());

          current = current->getNext();
        }

        ImGui::EndTable();
      }
    }

    ImGui::EndChild();
  }
}

void StudentFrame::controlsGroup() {

  int width = 16;
  int height = 1;

  if (ImGui::BeginChild("Buttons", ImVec2(70, 1), true)) {

    if (ImGui::Button("Guardar Archivo", ImVec2(width, height))) {
      h->saveAllStudents();
    }

    ImGui::SameLine();

    if (ImGui::Button("Cargar Archivo", ImVec2(width, height))) {
      h->readFile();
    }

    ImGui::SameLine();

    if (ImGui::Button("Dummy", ImVec2(width, height))) {
      h->dummy();
    }

    ImGui::SameLine();

    if (ImGui::Button("Salir", ImVec2(width, height))) {
      programRunning = false;
    }

    ImGui::SameLine();
  }
  ImGui::EndChild();
}
