#include "class_freqnote.h"

#define A 1.0594630943592952

using namespace freq;

int FreqNote::calcHalfStepOffset(std::string note)
{
	int n = note.at(note.length() - 1) - '0';

	n = (n - 4) * 12;

	if (note.length() == 2)
	{
		char c = note.at(0);

		if (c == 'C')
		n = n - 9;

		else if (c == 'D')
		n = n - 7;

		else if (c == 'E')
		n = n - 5;

		else if (c == 'F')
		n = n - 4;

		else if (c == 'G')
		n = n - 2;

		else if (c == 'B')
		n = n + 2;
	}

	else
	{
		char c = note.at(0);
		char d = note.at(1);

		if (c == 'D')
		{
			if (d == 'b')
			n = n - 8;

			else
			n = n - 6;
		}

		else if (c == 'G')
		{
			if (d == 'b')
			n = n - 3;

			else
			n = n - 1;
		}

		else if (c == 'A')
		{
			if (d == 'b')
			n = n - 1;

			else
			n = n + 1;
		}

		else if (c == 'C')
		n = n - 8;

		else if (c == 'E')
		n = n - 6;

		else if (c == 'B')
		n = n + 1;

		else
		n = n - 3;
	}

	return n;
}

float FreqNote::calcFreq(std::string note)
{
	if (note.length() > 3 || note.length() < 2)
	return -1;

	int n = calcHalfStepOffset(note);

	long double a = 440.00;

	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			a = a * A;
		}
	}

	else
	{
		for (int i = 0; i > n; i--)
		{
			a = a / A;
		}
	}

	return a;
}
