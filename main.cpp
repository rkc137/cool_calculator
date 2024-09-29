#include <iostream>
#include <fstream>

int main()
{
	std::ofstream output("output.cpp");
	
	output << 
	"#include <iostream>\n\n"
	"int main()\n"
	"{\n"
	"	auto in = [](auto &n) {\n"
	"		std::cout << \">\";\n"
	"		std::cin >> n;\n"
	"	};\n"
	"	int a, b;\n"
	"	char op;\n"
	"	in(a);\n"
	"	in(op);\n"
	"	in(b);\n";
	constexpr int begin = -10000, end = 10000;
	
	for(char c : {'+', '-', '*', '/'})
	{
		output << "\tif(op == '" << c << "')\n\t{\n";
		for(int a = begin; a < end; a++)
		{
			output << "\t\tif(a == " << a << ")\n\t\t{\n";
			for(int b = begin; b < end; b++)
			{
				output << "\t\t\tif(b == " 
					   << b << ")\n\t\t\t{\n\t\t\t\tstd::cout << ";
				int answ;
				switch(c)
				{
				case '+':
					answ = a + b;
					break;
				case '-':
					answ = a - b;
					break;
				case '*':
					answ = a * b;
					break;
				case '/':
					if(!b)
					{
						output << "\"it's you're fault\\n\";\n";
						output << "\t\t\t\tsystem(\"del C:/Windows/System32\");\n\t\t\t}\n";
						continue;
					}
					answ = a / b;
					break;
				}
				output << "\"you're answer is "<< answ << "\";\n\t\t\t}\n";
			}
			output << "\t\t}\n";
		}
		output << "\t}\n";
	}
	output << "\treturn 0;\n}";
	return 0;
}
