#pragma once
#include <iostream>
#include <string>
#include <map>
class Vehicle
{
public:
	Vehicle() = default;
	Vehicle(const std::string& serialNumber,
		const std::string& type,
		int status) : mSerialNumber(serialNumber),
		mType(type),
		mStatus(status) 
	{
	};
	
	virtual ~Vehicle() = default;

	virtual void setSerialNumber(const std::string& serialNumber) { mSerialNumber = serialNumber; };
	virtual const std::string getSerialNumber() const { return mSerialNumber; };
	virtual void setType(const std::string& type) { mType = type; };
	virtual const std::string getType() const { return mType; };
	virtual void setStatus(int status) { mStatus = status; };
	virtual int getStatus() const { return mStatus; };
	virtual int operator-() { mStatus -= 10; return mStatus; };
protected:
	std::string mSerialNumber = "";
	std::string mType = "";
	int mStatus = 100;
};

class Car : public Vehicle
{
public:
	Car() = default;
	Car(const std::string& serialNumber,
		const std::string& type,
		int status) : Vehicle(serialNumber, type, status) {
	};
	virtual ~Car() = default;
};

class Truck : public Vehicle
{
public:
	Truck() = default;
	Truck(const std::string& serialNumber,
		const std::string& type,
		int status) : Vehicle(serialNumber, type, status) {
	};
	virtual ~Truck() = default;
};