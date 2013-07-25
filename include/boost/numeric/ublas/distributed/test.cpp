#include "testDouble.hpp"
#include "controller.hpp"

using namespace boost::numeric::ublas::distributed;

int main(int argc, char** argv)
{
	Controller::init(argc, argv);
	std::cout << "\n" << std::endl;

	TestDouble t1(20.0);
	TestDouble t2(-2.0);
	TestDouble t4(10);
	TestDouble t3 = t1+t2;

	Controller::flush();
	dg("t3: " << t3.m_d);
	dg("fini");
	Controller::shutdown();
	return 0;
}
