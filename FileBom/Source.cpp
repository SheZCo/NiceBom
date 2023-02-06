#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <Windows.h>

int main()
{
	long i = 0; // counting
	const char* path = "C:\\Virus\\"; // file path
	std::string content = "Get file bomed 0x0"; // text to put in file
	_mkdir(path); // Mk the dir
	while (true) // Do forever, Until
	{
		i++; // Counting
		std::ofstream file; // output operations on file
		file.open(path + std::to_string(i) + ".txt", std::ios_base::out); // opening path, making file
		file << content; // output text to file
		file.close(); // close the file
		Sleep(1); // sleep
		std::cout << "File created: " + std::to_string(i) + "\r\n"; // User helping

		// ChatGpt Delete File Nice process
		if (GetAsyncKeyState(VK_RSHIFT) & 0X8000) // If rshift & "pressed"
		{
			system("color 4"); // Kill program and cleanup
			std::cout << "Killing Program." << std::endl;
			std::string command = "del /Q /F " + std::string(path) + "\\*.txt"; // Gpt Method of Deletion
			system(command.c_str());

			try {
				if (RemoveDirectoryA(path) == 0)
				{
					std::cerr << "Error Deleting Directory: " << GetLastError() << std::endl;
					return 1;
				}
				std::cout << "Successfully deleted the file: " << path << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				return 1;
			}
			Sleep(5000);
			break;
		}

	}

}