#pragma once

#include "main.h"
#include "liblvgl/lvgl.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <iomanip>

namespace GHUI { 

    void initialize_auton_selector();       
    void add_auton(std::function<void()> auton, 
                    std::string auton_name, bool isRedAlliance);
    void console_print(std::string text, int line);
    void run_selected_auton();
    void update_pos(double x, double y, double theta);
    
    lv_obj_t* create_button(lv_obj_t* parent, lv_coord_t x, 
                            lv_coord_t y, lv_coord_t width, 
                            lv_coord_t height, int id, const char* text);   

    void change_auton_event(lv_event_t* e); 
    void change_selected_auton(int index); 
    extern std::vector<std::pair<std::pair<std::string, bool>, std::function<void()>>> auton_list;
    extern std::unordered_map<lv_obj_t*, int> auton_map;  
}