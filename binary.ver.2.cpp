#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Класс шифрования BinaryV2.
 * Простая замена символов 0/1 на 2/3.
 */
class BinaryV2 {
public:
    // Метод для "кодирования" бинарной строки
    static string encrypt(const string& binaryInput) {
        if (binaryInput.empty()) return "";

        string encrypted = "";

        for (char c : binaryInput) {
            if (c == '0') {
                // Замена 0 на 2
                encrypted += "2"; 
            } else if (c == '1') {
                // Замена 1 на 3
                encrypted += "3";
            } else {
                // Если символов больше, кроме 0 и 1, они сохраняются как есть
                encrypted += c;
            }
        }
        return encrypted;
    }

    // Метод для декодирования бинарной строки
    static string decrypt(const string& cipherInput) {
        if (cipherInput.empty()) return "";

        string decrypted = "";

        for (char c : cipherInput) {
            if (c == '2') {
                // Замена 2 обратно на 0
                decrypted += "0";
            } else if (c == '3') {
                // Замена 3 обратно на 1
                decrypted += "1";
            } else {
                decrypted += c;
            }
        }
        return decrypted;
    }

    // Проверка: зашифровало и расшифровало ли оно верную строку (Test)
    static bool isRoundTripValid(const string& original, const string& cipher) {
        return original == decrypt(cipher);
    }

private:
    // Внутренние константы для скорости (хотя в данном случае не влияют на логику)
    static constexpr char ZERO_CODE = '0';
    static constexpr char ONE_CODE = '1';
    static constexpr char TWO_CODE = '2';
    static constexpr char THREE_CODE = '3';
};

int main() {
    // --- Тестовые данные ---
    
    cout << "=== Шифрование BinaryV2 ===" << endl;

    // 1. Простой тест из запроса
    string testStr1 = "0101";
    string encrypted1 = BinaryV2::encrypt(testStr1);
    cout << "Вход:   '" << testStr1 << "'" << endl;
    cout << "Выход:  '" << encrypted1 << "'" << endl;
    
    // 2. Дешифрование результата
    string decrypted1 = BinaryV2::decrypt(encrypted1);
    cout << "Декрипт:'" << decrypted1 << "'" << endl;
    cout << (testStr1 == decrypted1 ? "Верно!" : "Ошибка!") << endl << endl;

    // 3. Работа с большим количеством битов
    string bigBin = "10101010"; 
    string encryptedBig = BinaryV2::encrypt(bigBin);
    cout << "Вход (длинный): '" << bigBin << "'" << endl;
    cout << "Выход (шифр):   '" << encryptedBig << "'" << endl;

    // 4. Соединение (если бы это был реальный поток данных)
    string message = BinaryV2::encrypt("10"); // "32"
    message += " ";
    message += BinaryV2::encrypt("01"); // "23"
    cout << "\nТест соединения: '" << message << "'" << endl;
    cout << "Декрипт (всего): '" << BinaryV2::decrypt(message) << "'" << endl;

    // Скрипт запуска файла (если нужно читать из диска, замените консоль на fopen)
    /* 
       const string inputFile = "input.txt"; // имя вашего .txt файла 
       ifstream file(inputFile);
       if (file.is_open()) {
            // прочитай строку и зашифруй
       } 
    */

    return 0;
}
