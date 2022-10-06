#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Clock {
public:
	Clock();
	Clock(int, int, string);
	void setTime(int h, int m, string mer);
	void setHour(int);
	void setMinute(int);
	void setMeridiem(string);
	int getHour();
	int getMinute();
	string getMeridiem();

	void tick();
	string asString();
	string asStandard();

private:
	int hour, minute;
	string meridiem;

};

Clock::Clock() {
	setTime(12, 0, "am");
}
Clock::Clock(int h, int m, string s) {
	setTime(h, m, s);
}
void Clock::setTime(int h, int m, string s) {
	if (h <= 0 || h > 12) {
		cout << "invalid Hours" << endl;
		exit(1);
}
	if (m < 0 || m > 59) {
		cout << "invalid Minutes" << endl;
		exit(1);
	}
	if (s != "am" && s != "pm") {
		cout << "invalid meridiem" << endl;
		exit(1);
	}

	this->hour = h;
	this->minute = m;
	this->meridiem = s;
}
void Clock::setHour(int h) {
	setTime(h, minute, meridiem);
}
void Clock::setMinute(int x) {
	setTime(hour, x, meridiem);
}
void Clock::setMeridiem(string x) {
	setTime(hour, minute, x);
}

int Clock::getHour() {
	return hour;
}
int Clock::getMinute() {
	return minute;
}
string Clock::getMeridiem() {
	return meridiem;
}

string Clock::asString() {
	stringstream ss;
	ss << setfill('0') << setw(2) << hour << ":";
	ss << setfill('0') << setw(2) << minute << meridiem;
	return ss.str();
}
string Clock::asStandard() {
	int h = hour;
	if (h == 12) {
		h = 0;
	}
	if (meridiem == "pm") {
		h += 12;
	}
	stringstream ss;
	ss << setfill('0') << setw(2) << h << ":";
	ss << setfill('0') << setw(2) << minute;
	return ss.str();
}

void Clock::tick() {
	minute += 1;
	if (minute == 60) {
		minute = 0;
		// increment hour
		if (hour == 12) {
			hour = 1;
		}
		else {
			hour++;
		}

		if (hour == 12) {
			meridiem = (meridiem == "am" ? "pm" : "am");
		}
	}
}
int main() {

	Clock c;

	cout << "After default constructor: " << endl;
	cout << c.asString() << endl;
	cout << c.asStandard() << endl;
	c.tick();
	c.tick();

	cout << "After 2 ticks: " << endl;
	cout << c.asString() << endl;
	cout << c.asStandard() << endl;

	for (int i = 0; i < 185; i = i + 1)
		c.tick();

	cout << "After 185 more ticks: " << endl;
	cout << c.asString() << endl;
	cout << c.asStandard() << endl;
	cout << endl << endl;

	for (int i = 0; i < 250; i = i + 1)
		c.tick();

	cout << "After 250 more ticks: " << endl;
	cout << c.asString() << endl;
	cout << c.asStandard() << endl;
	cout << endl << endl;

	for (int i = 0; i < 500; i = i + 1)
		c.tick();

	cout << "After 401 more ticks: " << endl;
	cout << c.asString() << endl;
	cout << c.asStandard() << endl;
	cout << endl << endl;

	// Continue testing constructors and tick()
	Clock c1(11, 59, "am");
	cout << "After parameter constructor: " << endl;
	cout << c1.asString() << endl;
	cout << c1.asStandard() << endl;
	c1.tick();
	c1.tick();

	cout << "After 2 ticks: " << endl;
	cout << c1.asString() << endl;
	cout << c1.asStandard() << endl;

	for (int i = 0; i < 185; i = i + 1)
		c1.tick();

	cout << "After 185 more ticks: " << endl;
	cout << c1.asString() << endl;
	cout << c1.asStandard() << endl;
	cout << endl << endl;

	for (int i = 0; i < 250; i = i + 1)
		c1.tick();

	cout << "After 250 more ticks: " << endl;
	cout << c1.asString() << endl;
	cout << c1.asStandard() << endl;
	cout << endl << endl;

	for (int i = 0; i < 500; i = i + 1)
		c1.tick();

	cout << "After 401 more ticks: " << endl;
	cout << c1.asString() << endl;
	cout << c1.asStandard() << endl;
	cout << endl << endl;

	return 0;

}