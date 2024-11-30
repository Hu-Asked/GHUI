#include "main.h"

pros::Motor motor(1);

void RedRings() {
	motor.move(127);
	pros::delay(500);
	motor.move(0);
}

void r1() {
	motor.move(127);
	pros::delay(2500);
	motor.move(0);
}
void r2() {
	motor.move(127);
	pros::delay(2000);
	motor.move(0);
}
void r3() {
	motor.move(127);
	pros::delay(1000);
	motor.move(0);
}
void r4() {
	motor.move(127);
	pros::delay(1500);
	motor.move(0);
}

void b1() {
	motor.move(50);
	pros::delay(500);
	motor.move(0);
}
void b2() {
	motor.move(50);
	pros::delay(1000);
	motor.move(0);
}
void b3() {
	motor.move(50);
	pros::delay(1500);
	motor.move(0);
}
void b4() {
	motor.move(50);
	pros::delay(2500);
	motor.move(0);
}



/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	GHUI::initialize_auton_selector({
		GHUI::Auton(RedRings, "Red Rings", GHUI::AutonType::RED),
		GHUI::Auton(r1, "Red 1", GHUI::AutonType::RED),
		GHUI::Auton(r2, "Red 2", GHUI::AutonType::RED),
		GHUI::Auton(r3, "Red 3", GHUI::AutonType::RED),
		GHUI::Auton(r4, "Red 4", GHUI::AutonType::RED),
		GHUI::Auton(b1, "Blue 1", GHUI::AutonType::BLUE),
		GHUI::Auton(b2, "Blue 2", GHUI::AutonType::BLUE),
		GHUI::Auton(b3, "Blue 3", GHUI::AutonType::BLUE),
		GHUI::Auton(b4, "Blue 4", GHUI::AutonType::BLUE)
	});
	GHUI::console_print("Initialized", 0);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	GHUI::run_selected_auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	int count = 0;
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	while(true) {
		lv_task_handler();
		GHUI::update_pos(count, count, count);
		pros::delay(50);
		count+= 1;
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			autonomous();
		}
	}
}