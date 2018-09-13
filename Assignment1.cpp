#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	cout << "Enter a string (Only use ^, V, !, A-Z): ";
	getline(cin, input);

	bool lastWasAlpha = false;
	bool lastWasNot = false;
	bool lastWasConnector = false;
	bool isValidWff = true;

	for (unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (c == ' ')
			continue;
		if (c == '^' || c == '!' || toupper(c) == 'V')
		{
			if (c != '!')
			{
				if (!lastWasAlpha)
				{
					isValidWff = false;
					break;
				}
				lastWasConnector = true;
			}
			else
			{
				if (lastWasAlpha)
				{
					isValidWff = false;
					break;
				}
				lastWasNot = true;
				continue;
			}
			lastWasAlpha = false;
		}
		else if (isalpha(c))
		{
			if (lastWasAlpha)
			{
				isValidWff = false;
				break;
			}
			lastWasAlpha = true;
			continue;
		}
		else
		{
			isValidWff = false;
			break;
		}
	}
	cout << (isValidWff ? "That is a WFF" : "NOT Valid WFF") << endl;

	return 0;
}
