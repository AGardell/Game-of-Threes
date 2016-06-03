//Simple program to play the "Threes" game. The game involves taking a number and dividing by three. If number is not
//divisible by three, either add 1 or subtract 1 to make it divisible. Continue until you reach 1.

#include <iostream>
#include <queue>
#include <string>


std::queue<std::string> qu;

void playThrees(int& num) {
	while (num != 1) {
		if (num % 3 == 0) { //check to see what needs to be done to make the number divisible by three.
			qu.push(std::to_string(num) + " 0");
			num = num / 3;
			playThrees(num);
		}
		else if ((num + 1) % 3 == 0) {
			qu.push(std::to_string(num) + " 1");
			num = (num + 1) / 3;
			playThrees(num);
		}
		else {
			qu.push(std::to_string(num) + " -1");
			num = (num - 1) / 3;
			playThrees(num);
		}
	}

}

int main() {
	int num = 0;
	std::cout << "Please enter a number: ";
	std::cin >> num;
	playThrees(num);

	qu.push(std::to_string(num)); //push back final number, which is always 1.

	while (!qu.empty()) { //pop off number one at a time.
		std::cout << qu.front() << std::endl;
		qu.pop();
	}

	return 0;
}