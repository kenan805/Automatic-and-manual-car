#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

class Car {
protected:
	int _id;
	string _model;
	string _color;
	int _year;
public:
	Car() :_id(), _model(), _color(), _year()
	{

	}
	Car(const int id, const string& model, const string& color, const int year)
	{
		SetId(id);
		SetModel(model);
		SetColor(color);
		SetYear(year);
	}

	int GetId()const
	{
		return _id;
	}
	string GetModel()const
	{
		return _model;
	}
	string GetColor()const
	{
		return _color;
	}
	int GetYear()const
	{
		return _year;
	}

	void SetId(const int id)
	{
		assert(id >= 0 && "id < 0");
		_id = id;
	}
	void SetModel(const string& model)
	{
		if (model.empty()) return;
		_model = model;
	}
	void SetColor(const string& color)
	{
		if (color.empty()) return;
		_color = color;
	}
	void SetYear(const int year)
	{
		assert(year >= 0 && "Year < 0");
		_year = year;
	}

	virtual void show() {
		cout << "+++++++++++ Car Info +++++++++++" << endl;
		cout << "Id: " << GetId() << endl;
		cout << "Model: " << GetModel() << endl;
		cout << "Color: " << GetColor() << endl;
		cout << "Year: " << GetYear() << endl;
	}
};

class Manual :public Car {
protected:
	bool _outShaft;
public:
	Manual() :_outShaft()
	{

	}
	Manual(const int id, const string& model, const string& color, const int year, const bool outShaft) :Car(id, model, color, year)
	{
		SetOutShaft(outShaft);
	}

	bool GetOutShaft()const
	{
		return _outShaft;
	}
	void SetOutShaft(const bool outShaft)
	{
		_outShaft = outShaft;
	}

	void show() override {
		Car::show();
		if (GetOutShaft() == 1) cout << "Out shaft: Yes" << endl;
		else cout << "Out shaft: No" << endl;
	}
};

class Automatic :public Car {
protected:
	string _converter;
public:
	Automatic() :_converter()
	{

	}
	Automatic(const int id, const string& model, const string& color, const int year, const string& converter) :Car(id, model, color, year)
	{
		SetConverter(converter);
	}

	string GetConverter()const
	{
		return _converter;
	}
	void SetConverter(const string& converter)
	{
		_converter = converter;
	}

	void show() override {
		Car::show();
		cout << "Converter: " << GetConverter() << endl;
	}
};

class Mercedes :public Automatic {
protected:
	bool _amg_packet;
public:
	Mercedes() :_amg_packet()
	{

	}
	Mercedes(const int id, const string& model, const string& color, const int year, const string& converter, const bool amg_packet) :Automatic(id, model, color, year, converter)
	{
		SetAmgPacket(amg_packet);
	}

	bool GetAmgPacket()const
	{
		return _amg_packet;
	}
	void SetAmgPacket(const bool amg_packet)
	{
		_amg_packet = amg_packet;
	}

	void show()  override final {
		Automatic::show();
		if (GetAmgPacket() == 1) cout << "AMG Packet: Yes" << endl << endl;
		else cout << "AMG Packet: No" << endl << endl;
	}
};

class Bmw :public Automatic {
protected:
	bool _m_packet;
public:
	Bmw() :_m_packet()
	{

	}
	Bmw(const int id, const string& model, const string& color, const int year, const string& converter, const bool m_packet) :Automatic(id, model, color, year, converter)
	{
		SetMPacket(m_packet);
	}

	bool GetMPacket()const
	{
		return _m_packet;
	}
	void SetMPacket(const bool m_packet)
	{
		_m_packet = m_packet;
	}

	void show() override final {
		Automatic::show();
		if (GetMPacket() == 1) cout << "M Packet: Yes" << endl << endl;
		else cout << "M Packet: No" << endl << endl;
	}
};

class Hyundai :public Manual {
protected:
	string _hyundai_detal;
public:
	Hyundai() :_hyundai_detal()
	{

	}
	Hyundai(const int id, const string& model, const string& color, const int year, const bool outShaft, const string& hyundai_detal) :Manual(id, model, color, year, outShaft)
	{
		SetHyundaiDetal(hyundai_detal);
	}

	string GetHyundaiDetal()const
	{
		return _hyundai_detal;
	}
	void SetHyundaiDetal(const string& hyundai_detal)
	{
		_hyundai_detal = hyundai_detal;
	}

	void show() override final {
		Manual::show();
		cout << "Hyundai detal: " << GetHyundaiDetal() << endl << endl;
	}
};

void report(Car& car) {
	car.show();
}

int main() {
	Bmw b1(1, "M5 Competition", "Matte blue", 2015, "Torque converter", true);
	Mercedes m1(2, "S63 AMG", "white", 2016, "Catalytic converter", true);
	Hyundai h1(3, "Accent", "grey", 2013, false, "hyundai detal");

	vector<Car*> cars;
	cars.push_back(&b1);
	cars.push_back(&m1);
	cars.push_back(&h1);

	for (size_t i = 0; i < cars.size(); i++)
	{
		report(*cars[i]);
	}
	

}
