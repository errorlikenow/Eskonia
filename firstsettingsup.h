#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int firstsettingup() {
    ofstream RegKey("System.reg");
    if (!RegKey.is_open())
    {
        ofstream RegKey("System.txt");
        if (!RegKey.is_open())
        {
            setlocale(LC_ALL, "Rus");
            cout << "Ошибка создания файла! Перезагрузите ОС!";
	   system("FirstSettingUp.exe");
	   return 1;
        }
    }
    string rasklav;
    setlocale(LC_ALL, "Rus");
    cout << "Выберите язык из списка который вы хотите выбрать-\n Russia \n English \n China\n";
    string language;
    cin >> language;
    if (language == "Russia"){
    cout << "Привет, мир!\n";
    sleep(2);
    cout << "Я полагаю что вы будете использовать Русскую раскладку клавиатуры (Y - да, N - нет)\n";
    char rasklavyn;
    cin >> rasklavyn;
    if (rasklavyn == 'Y') {}
    else if (rasklavyn == 'N'){
	char A;
	do A == 'Y'; while(A == 'Y');{
	cout << "Тогда выберите одну из этих раскладок клавиатуры - \n Русская \n Английская \n Китайская \n";
	cin >> rasklav;
	cout << "Ваша раскладка клавиатуры " << rasklav << " (Y - да, N - нет)?\n";
	cin >> A;
	}
	}
    else {
		cout << "Введите допустимый символ!";
		cin >> rasklavyn;
	}
    cout << "А теперь давайте создадим вашего пользователя.\nВведите имя пользователя и пароль\n";
    string user, password;
    cin >> user;
    cin >> password;
    cout << "Настройка окончена. Мы молодцы :)\n";
    sleep(5);
    cout << "Пасхалка от автора- на рабочем столе вы увидите файл. Прочитайте его перед удалением!\n";
    RegKey << R"(region system:
    region settings:
        key language:[)" << language << R"(]
        key keyboardlanguage:[)" << rasklav << R"(]
        key nameuser:[)" << user << R"(]
        key passworduser:[)" << password << R"(]
    close region settings
close region system)";
    }
    else if (language == "English"){
    setlocale(LC_ALL, "En");
    cout << "Hello, world!\n";
    sleep(2);
        cout << "I assume that you will use the Russian keyboard layout (Y - yes, N - no)\n";
    char rasklavyn;
    cin >> rasklavyn;
    if (rasklavyn == 'Y') {}
    else if (rasklavyn == 'N'){
	char A;
	do A == 'Y'; while(A == 'Y');{
	cout << "Then choose one of these keyboard layouts - \n Russian \n English \n Chinese \n";
	cin >> rasklav;
	cout << "Is Your keyboard layout " << rasklav << " (Y - yes, N - no)?\n";
	cin >> A;
	}
	}
    else {
		cout << "Enter a valid character!";
		cin >> rasklavyn;
	}
    cout << "Now let's create your user.\nEnter the username and password\n";
    string user, password;
    cin >> user;
    cin >> password;
    cout << "The settings up is over. We did well :)\n";
    sleep(5);
    cout << "A surprise from the author - you will see a file on your desktop. Read it before deleting it!\n";
    RegKey << R"(region system:
    region settings:
        key language:[)" << language << R"(]
        key keyboardlanguage:[)" << rasklav << R"(]
        key nameuser:[)" << user << R"(]
        key passworduser:[)" << password << R"(]
    close region settings
close region system)";
    }
    else if (language == "China"){
    setlocale(LC_ALL, "Ch");
    cout << "你好，世界!";
    sleep(2);
    cout << "我假设您将使用俄语键盘布局(Y - 是的，N - 非也。)";
    char rasklavyn;
    cin >> rasklavyn;
    if (rasklavyn == 'Y') {}
    else if (rasklavyn == 'N'){
	char A;
	do A == 'Y'; while(A == 'Y');{
	cout << "然后选择这些键盘布局之一-\n俄语\n英语\n中文\n";
	cin >> rasklav;
	cout << "是你的键盘布局 " << rasklav << " (Y - 是的, N - 非也。 )?\n";
    cin >> A;
    }
    }
    else {
        cout << "输入一个有效的字符!";
        cin >> rasklavyn;
    }
    cout << "现在让我们创建您的用户。\n 输入用户名和密码\n";
    string user, password;
    cin >> user;
    cin >> password;
    cout << "设置结束了。 我们做得很好 :)\n";
    sleep(5);
    cout << "来自作者的惊喜-您将在桌面上看到一个文件。 在删除它之前阅读它!\n";
    RegKey << R"(region system:
    region settings:
        key language:[)" << language << R"(]
        key keyboardlanguage:[)" << rasklav << R"(]
        key nameuser:[)" << user << R"(]
        key passworduser:[)" << password << R"(]
    close region settings
close region system)";

    }
    else {
        cout << "Вы некорректно ввели язык! Повторите попытку!";
    }
    return 0;
}