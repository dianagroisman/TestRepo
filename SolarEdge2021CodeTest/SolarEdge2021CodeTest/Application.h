#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Vehicle.h"

enum MenuOption {
	MAIN_MENU_ADD_VEHICLE = 1,
	MAIN_MENU_REPORT_ACCIDENT = 2,
	MAIN_MENU_PRINT_ALL = 3,
	MAIN_MENU_EXIT = 4
};

enum VehicleMenuOption
{
	VEHICLE_MENU_ENTER_SERIAL_NUMBER = 1,
	VEHICLE_MENU_ENTER_VEHICLE_TYPE = 2,
	VEHICLE_MENU_ENTER_VEHICLE_STATUS = 3
};

class Application
{
public:
	Application();

	void Run();
private:
	void PrintMenu() const;
	void HandleMenu();
	void HandleAddVehicleMenu();
	void HandleReportAnAccidentMenu();
	void PrintAllVehicles() const;

	int mMenuOption = -1;
	std::map<std::string, std::shared_ptr<Vehicle> > mVehicles;
};
