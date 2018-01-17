//
// Created by Artem Bobrov on 17.01.2018.
//

#include "plotter.h"

void Plotter::_format(std::string &function) {
	boost::replace_all(function, "^", "**");
}
void Plotter::plot(std::string function) {
	_format(function);

	std::string leftEdge = std::to_string(-10);
	std::string rightEdge = std::to_string(10);

	std::vector<std::string> script;

	script.emplace_back(" set terminal x11");
	script.emplace_back(" reset");
	script.emplace_back(" set xzeroaxis lt -1");
	script.emplace_back(" set yzeroaxis lt -1 \n");
	script.emplace_back(" set xrange [" + leftEdge + ":" + rightEdge + "] \n");
	script.emplace_back(" set yrange [" + leftEdge + ":" + rightEdge + "] \n");
	script.emplace_back(" unset border \n");
	script.emplace_back(" unset tics \n");
	script.emplace_back(" set xtics axis " + leftEdge + ",1," + rightEdge + " \n");
	script.emplace_back(" set ytics axis " + leftEdge + ",1," + rightEdge + " \n");
	script.emplace_back(" plot " + function);

	GNUPlot plotter;
	plotter.open();
	plotter.execute(script);

	std::this_thread::sleep_until(std::chrono::time_point<std::chrono::system_clock>::max());

	plotter.write("exit");
	plotter.flush();
	plotter.close();

}
