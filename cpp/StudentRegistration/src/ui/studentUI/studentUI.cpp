
#include "studentUI.h"
#include "../utils/frameVisibility.h"
#include "imgui/imgui.h"
#include "imtui/imtui-impl-ncurses.h"

void StudentFrame::addStudentFrame() {

  // Panel con borde
  if (ImGui::BeginChild("FormPanel", ImVec2(30, 30), true,
                        ImGuiWindowFlags_AlwaysUseWindowPadding)) {

    // Campos numéricos
    ImGui::Text("Números");
    ImGui::InputFloat("Decimal", &numero_decimal);
    ImGui::InputInt("Entero", &numero_entero);

    // Campos de texto
    ImGui::Text("Texto");
    ImGui::InputText("Campo 1", texto1, sizeof(texto1));
    ImGui::InputText("Campo 2", texto2, sizeof(texto2));

    // Radio buttons
    ImGui::Text("Opciones");
    ImGui::RadioButton("Primera", &radio_selection, 0);
    ImGui::SameLine();
    ImGui::RadioButton("Segunda", &radio_selection, 1);
  }

  // Botón
  if (ImGui::Button("Ejecutar", ImVec2(-1, 0))) {
    // Acción del botón
    // printf("Botón presionado!\n");
  }

  ImGui::EndChild();
}

void StudentFrame::studentListTable() {

  if (showStudentTable) {

    if (ImGui::BeginChild("FormPanel1")) {
      if (ImGui::BeginTable("MiTabla", 3)) {

        // Encabezados
        ImGui::TableSetupColumn("Nombre");
        ImGui::TableSetupColumn("Edad");
        ImGui::TableSetupColumn("Ciudad");
        ImGui::TableHeadersRow();

        // Filas de datos
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Juan");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("25");
        ImGui::TableSetColumnIndex(2);
        ImGui::Text("Madrid");

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("María");
        ImGui::TableSetColumnIndex(1);
        ImGui::Text("30");
        ImGui::TableSetColumnIndex(2);
        ImGui::Text("Barcelona");

        ImGui::EndTable();
      }
    }

    ImGui::EndChild();
  }
}

void StudentFrame::controlsGroup() {

  int width = 10;
  int height = 1;

  if (ImGui::BeginChild("Buttons", ImVec2(60, 1), true)) {

    if (ImGui::Button("Guardar", ImVec2(width, height))) {
      // Acción del botón
      // printf("Botón presionado!\n");
    }

    ImGui::SameLine();

    if (ImGui::Button("Cargar", ImVec2(width, height))) {
      // Acción del botón
      // printf("Botón presionado!\n");
    }

    ImGui::SameLine();

    if (ImGui::Button("Dummy", ImVec2(width, height))) {
      // Acción del botón
      // printf("Botón presionado!\n");
    }

    ImGui::SameLine();

    if (ImGui::Button("Salir", ImVec2(width, height))) {
      programRunning = false;
    }

    ImGui::SameLine();
  }
  ImGui::EndChild();
}
