//Да се напише функция, която приема цяло число n и масив от n цели числа. Да се намери и изведе броя на тези числа в масива,
//чийто сбор от цифрите е едноцифрено число. Ако няма такива да се изведе подходящо съобщение.

const int SIZE = 100;

int countNumbers(int size, int numbers[]);
void find(int size, char str[], char symbol);
void replace(int size, char str[], char symbol);

int main()
{
 int size;
 int numbers[SIZE] = {0};

 do
 {
   cin >> size;
 } while(size > 100 && size < 1);

 for(int i = 0; i < size; i++)
 {
   cin >> numbers[i];
 }
 cout << "Numbers with correct digit sum is: " << countNumbers(size, numbers);
}

int countNumbers(int size, int numbers[])
{
 int sum = 0, counter = 0;
 for(int i = 0; i < size; i++)
 {
   sum = 0;
   while(numbers[i])
   {
     sum += numbers[i] % 10;
     numbers[i] /= 10;
   }
   if(sum < 10)
     counter++;
 }

 return counter;
}


//Да се напише функция, която приема низ и символ. Да се изведе колко пъти се среща символът в низа и , ако се среща да го замести със символа *.

void find(int size, char str[], char symbol)
{
 int counter = 0;
 for(int i = 0; i < size; i++)
 {
   if(str[i] == symbol)
     counter++;
 }

 cout << "Symbol found " << counter << " times." << endl;
}

void replace(int size, char str[], char symbol)
{
 for(int i = 0; i < size; i++)
 {
   if(str[i] == symbol)
     str[i] = '*';
 }
 cout << "New string:" << endl;
 for(int i = 0; i < size; i++)
 {
   cout << str[i];
 }
}

//Да се напише функция, която приема цяло положително число n и да се създаде масив от реални числа, n на брой.
//Запълнете масива с въведени от клавиатурата стойности. След това да се въведе още едно число, което служи за:
// - да се определи дали се среща числото в масива и ако да, колко пъти
// - ако числото се среща в масива, да се определят и отпечатат всички позиции, на които то се среща

void find(int size, double numbers[], int num)
{
 int counter = 0;
 for(int i = 0; i < size; i++)
 {
   if(numbers[i] == num)
   {
     counter++;
     cout << "Number found on position " << i << endl;
   }
 }

 if(counter == 0)
 {
   cout << "Number not found" << endl;
 }
 else
 {
   cout << "Number found " << counter << " times." << endl;
 }
}

//Да се напише функция, която приема символен низ, преобразува го като всяка малка буква стане главна и обратно, а символите ", . ! ?" не се променят.

int main ()
{
 char str[100];
 int n;
 int letterDiff = 'a' - 'A';
 cin >> n;

 for(int i = 0; i < n; i++)
 {
   cin >> str[i];
   if (str[i] >= 'a' && str[i] <= 'z')
    str[i] -= letterDiff;
   else if(str[i] >= 'A' && str[i] <= 'Z')
    str[i] += letterDiff;
 }

 for(int i = 0; i < n; i++)
  cout << str[i];

 cout<<endl;
 
 return 0;

}

//Да се напише програма за счетоводство. Трябва да приема масив от цени на продукти,
//сортира ги възходящо, извежда средна стойност на продуктите и общата сума на покупката. Програмата трябва да съдържа отделни функции за всяко действие.

int main()
{
 double prices[SIZE] = {0};
 int n = 0;
 cin >> n;
 for(int i = 0; i < n; i++)
 {
   cin >> prices[i];
 }

 findStatistics(n, prices);
 sort(n, prices);

 return 0;
}

void findStatistics(int n, double prices[])
{
 double avg = 0, sum = 0;
 for(int i = 0; i < n; i++)
 {
   sum += prices[i];
 }

 avg = sum / n;

 cout << "Avg: " << avg << endl;
 cout << "Sum: " << sum << endl;
}

void sort(int n, double prices[])
{
   double min = prices[0];
   int minPos = 0;
   for (int i = 0; i < n; i++)
   {
       min = prices[i];
       minPos = i;

       for (int j = i + 1; j < n; j++)
       {
           if (prices[j] < min)
           {
               min = prices[j];
               minPos = j;
           }
       }

       double temp = prices[i];
       prices[i] = prices[minPos];
       prices[minPos] = temp;
   }

   for (int j = 0; j < n; j++)
   {
       cout << prices[j] << " ";
   }
   cout << endl;
}
