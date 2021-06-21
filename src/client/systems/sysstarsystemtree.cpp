/*
 * Copyright 2021 Conquer Space
 */
#include "client/systems/sysstarsystemtree.h"

#include <string>

#include "client/systems/sysstarsystemrenderer.h"
#include "client/scenes/universescene.h"
#include "common/components/bodies.h"
#include "common/components/name.h"

void conquerspace::client::systems::SysStarSystemTree::Init() {}

void conquerspace::client::systems::SysStarSystemTree::DoUI(int delta_time) {
    namespace cqspb = conquerspace::components::bodies;
    namespace cqspcs = conquerspace::client::systems;
    // Get star system
    entt::entity ent =
        GetApp().GetUniverse().view<cqspcs::RenderingStarSystem>().front();
    if (ent == entt::null) {
        return;
    }
    auto& star_system = GetApp().GetUniverse().get<cqspb::StarSystem>(ent);
    ImGui::SetNextWindowPos(ImVec2(30, ImGui::GetIO().DisplaySize.y - 30),
                            ImGuiCond_Always, ImVec2(0.f, 1.f));
    ImGui::SetNextWindowSize(ImVec2(200, 400), ImGuiCond_Always);
    ImGui::Begin("Star System (Will add name soon)",
                NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    if (ImGui::BeginListBox("Star Systems", ImVec2(-FLT_MIN, -FLT_MIN))) {
        int index = 0;
        // Get selected planet
        entt::entity current_planet = conquerspace::scene::GetCurrentViewingPlanet(GetApp());
        for (auto entity : star_system.bodies) {
            bool is_selected = (entity == current_planet);
            std::string star_system_name = fmt::format("{}", entity);
            if (GetApp().GetUniverse().all_of<conquerspace::components::Name>(entity)) {
                star_system_name = fmt::format(
                    "{}", GetApp().GetUniverse().get<conquerspace::components::Name>(entity)
                            .name);
            }

            if (ImGui::Selectable(star_system_name.c_str(),
                            is_selected, ImGuiSelectableFlags_AllowDoubleClick)) {
                // Selected object
                selected_index = index;
                if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
                    // Go to the planet
                    conquerspace::scene::SeePlanet(GetApp(), entity);
                }
            }
            index++;
        }
        ImGui::EndListBox();
    }
    ImGui::End();
}

void conquerspace::client::systems::SysStarSystemTree::DoUpdate(
    int delta_time) {}
