#include "Application.h"
#include <memory>

Application::Application()
{
	mVehicles.clear();
}

void Application::Run()
{
	do
	{
		PrintMenu();
		std::cin >> mMenuOption;
		HandleMenu();
	} while ((mMenuOption != MenuOption::MAIN_MENU_EXIT) );
}

void Application::PrintMenu() const
{
	std::cout << "Please select an option : \n";
	std::cout << "1 - Add a new vehicle\n";
	std::cout << "2 - Report an accident\n";
	std::cout << "3 - Print all vehicles\n";
	std::cout << "4 - Exit\n";
}

void Application::HandleMenu()
{
	switch (mMenuOption)
	{
	case MenuOption::MAIN_MENU_ADD_VEHICLE:
		// Add Vehicle menu
		HandleAddVehicleMenu();
		break;
	case MenuOption::MAIN_MENU_REPORT_ACCIDENT:
		//Report an excident
		HandleReportAnAccidentMenu();
		break;
	case MenuOption::MAIN_MENU_PRINT_ALL:
		PrintAllVehicles();
		break;
	case MenuOption::MAIN_MENU_EXIT:
		break;
	default:
		std::cout << "Unknown menu option. Unable to perform. Exiting ...\n";
	} // switch
}

void Application::HandleAddVehicleMenu()
{
	std::cout << "Please enter serial number : \n";
	std::string serial_number = "";
	std::cin >> serial_number;
	bool found = false;

	while (mVehicles.find(serial_number) != mVehicles.end())
	{
		std::cout << "Vehicle with serial number = " << serial_number << " already exists.\n";
		std::cout << "Please enter serial number : \n";
		found = true;
		std::cin >> serial_number;
	}

	std::cout << "Please enter the vehicle's type: \n";
	std::cout << "Vehicle types are: car, truck\n";
	std::string type = "";
	std::cin >> type;
	
	std::shared_ptr<Vehicle> v_ptr = std::make_shared<Vehicle>(serial_number, type, 100);
	mVehicles[serial_number] = v_ptr;

	std::cout << type << " with serial number " << serial_number << " is added successfully\n";
} 
	
void Application::HandleReportAnAccidentMenu()
{
	std::cout << "Please, enter how many vehicles involved in the accident?\n";
	unsigned int num_vehicles = 0;
	std::cin >> num_vehicles;
	int min_status = 100;
	std::string min_sn = "";

	std::cout << "The result of the Accident is:\n";
	for (int i = 0; i < num_vehicles; ++i)
	{
		std::cout << "Please, enter vehicle's serial number:\n";
		std::string sn;
		std::cin >> sn;

		auto vehicle = mVehicles.find(sn);
		if (vehicle == mVehicles.end())
		{
			std::cout << "Error! No vehicle with serial number " << sn << " found\n";
			return;
		}

		int new_status = vehicle->second->operator-();
		std::cout << vehicle->second->getSerialNumber() << " status = " << vehicle->second->getStatus() << std::endl;
		
		if (min_status > new_status)
		{
			min_status = new_status;
			min_sn = vehicle->second->getSerialNumber();
		}
	} // for

	std::cout << "The vehicle with minimal status is: " << min_sn << " status = " << min_status << std::endl;
}

void Application::PrintAllVehicles() const
{
	for (const auto& vehicle : mVehicles)
	{
		std::cout << vehicle.second->getSerialNumber() << " " << vehicle.second->getType() << " " << vehicle.second->getStatus() << std::endl;
	}
}
