//Task EGN arr
const int EGN_LENGTH = 10;

void enterEGN(int egn[EGN_LENGTH]);
int getYear(const int egn[EGN_LENGTH]);
int getMonth(const int egn[EGN_LENGTH]);
int getDay(const int egn[EGN_LENGTH]);
bool isMale(const int egn[EGN_LENGTH]);
void egnToArray(long number, int egn[]);

int main()
{
  int egn[EGN_LENGTH];
  long long egnWhole;

  std::cout << "Please eneter your EGN: ";
  std::cin >> egnWhole;

  egnToArray(egnWhole, egn);

  std::cout << getYear(egn) << " " << getMonth(egn) << " " << getDay(egn) << " " << (isMale(egn) ? "Male" : "Female");
}

void enterEGN(int egn[EGN_LENGTH])
{
  for (int i = 0; i < EGN_LENGTH; i++)
  {
      std::cout << egn[i];
  }
}

void egnToArray(long number, int egn[])
{
  int iterator = EGN_LENGTH - 1;
  while (number > 0)
  {
      egn[iterator] = number % 10;
      number /= 10;
      iterator--;

      if (number == 0 && iterator >= 0)
      {
          while (iterator >= 0)
          {
              egn[iterator] = 0;
              iterator--;
          }
      }
  }
}

int getYear(const int egn[EGN_LENGTH])
{
  if (egn[0] == 0)
  {
      return 2000 + egn[1];
  }

  if (egn[0] >= 1 && egn[0] <= 1)
  {
      return 2000 + (egn[0] * 10 * egn[1]);
  }

  return 1900 + (egn[0] * 10 + egn[1]);
}

int getMonth(const int egn[EGN_LENGTH])
{
  int month = egn[2] * 10 + egn[3];

  if(getYear(egn) >= 2000)
      return month - 40;

  return month;
}

int getDay(const int egn[EGN_LENGTH])
{
  return egn[4] * 10 + egn[5];
}

bool isMale(const int egn[EGN_LENGTH])
{
  return egn[8] % 2 == 0;
}
