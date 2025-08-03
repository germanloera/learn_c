#include "imtui/imtui.h"
#include "imtui/imtui-impl-ncurses.h"

#include <thread>
#include <chrono>

int show() {
    // Verificar versión de ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    // Inicializar ImTui
    auto screen = ImTui_ImplNcurses_Init(true);
    ImTui_ImplText_Init();
    
    // Variables de la aplicación
    bool show_demo = false;
    int counter = 0;
    float slider_value = 0.5f;
    char text_buffer[256] = "Escribe aquí...";
    
    bool done = false;
    while (!done) {
        // Nuevo frame
        ImTui_ImplNcurses_NewFrame();
        ImTui_ImplText_NewFrame();
        ImGui::NewFrame();
        
        // Ventana principal
        if (ImGui::Begin("Mi Primera App ImTui")) {
            ImGui::Text("¡ImTui funciona correctamente!");
            ImGui::Separator();
            
            // Botón contador
            if (ImGui::Button("Incrementar")) {
                counter++;
            }
            ImGui::SameLine();
            ImGui::Text("Contador: %d", counter);
            
            // Slider
            ImGui::SliderFloat("Valor", &slider_value, 0.0f, 1.0f);
            
            // Input de texto
            ImGui::InputText("Texto", text_buffer, sizeof(text_buffer));
            
            // Checkbox para demo
            ImGui::Checkbox("Mostrar Demo", &show_demo);
            
            ImGui::Separator();
            
            // Botón salir
            if (ImGui::Button("Salir")) {
                done = true;
            }
        }
        ImGui::End();
        
        // Ventana demo opcional
        if (show_demo) {
            ImGui::ShowDemoWindow(&show_demo);
        }
        
        // Renderizar
        ImGui::Render();
        ImTui_ImplText_RenderDrawData(ImGui::GetDrawData(), screen);
        ImTui_ImplNcurses_DrawScreen();
        
        // Control de FPS
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    
    // Cleanup
    ImTui_ImplText_Shutdown();
    ImTui_ImplNcurses_Shutdown();
    
    return 0;
}