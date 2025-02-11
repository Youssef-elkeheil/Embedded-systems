/* A utility function to reverse a string */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length -1;
    char temp;
	while (start < end)
	{
        temp = str[start];
        str[start] = str[end];
        str[end]= temp;
		start++;
		end--;
	}
}

// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
	int i = 0;
	char isNegative = 0;

	/* Handle 0 explicitly, otherwise empty string is printed for 0 */
	if (num == 0)
	{
		str[i] = '0';
        i++;
		str[i] = '\0';
		return str;
	}

	// In standard itoa(), negative numbers are handled only with
	// base 10. Otherwise numbers are considered unsigned.
	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}

	// Process individual digits
	while (num != 0)
	{
		int rem = num % base;
		str[i] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        i++;
		num = num/base;
	}

	// If number is negative, append '-'
	if (isNegative)
    {
		str[i] = '-';
        i++;
    }

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse(str, i);

	return str;
}
