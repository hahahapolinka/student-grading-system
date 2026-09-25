#include <iostream>
#include <string>
#include "CommandProcessor.hpp"
#include "StudentsDataBase.hpp"

void print_help() {
    std::cout << "Использование: students [файл_базы] | --help | --check <файл>\n\n";
    std::cout << "Режимы запуска:\n";
    std::cout << "  students                : запуск с пустой базой\n";
    std::cout << "  students <file>         : загрузка базы из файла <file>\n";
    std::cout << "  students --help         : вывод этой справки\n";
    std::cout << "  students --check <file> : проверка корректности файла <file>\n\n";
    std::cout << "Интерактивные команды доступны после старта.\n";
}

bool check_file_validity(const std::string& filename) {
    gavrilova::StudentDatabase db;
    bool ok = db.loadFromFile(filename);
    if (ok) {
        std::cout << "Файл '" << filename << "' корректен.\n";
    } else {
        std::cerr << "Ошибка: файл '" << filename << "' поврежден или имеет неверный формат.\n";
    }
    return ok;
}

int main(int argc, char* argv[])
{
    if (argc > 1 && std::string(argv[1]) == "--help") {
        print_help();
        return 0;
    }

    if (argc > 2 && std::string(argv[1]) == "--check") {
        std::string filename = argv[2];
        bool valid = check_file_validity(filename);
        return valid ? 0 : 1;
    }

    gavrilova::StudentDatabase db;

    if (argc > 1) {
        std::string filename = argv[1];
        std::cout << "Загрузка данных из файла: " << filename << '\n';
        if (!db.loadFromFile(filename)) {
            std::cerr << "Ошибка: не удалось загрузить данные из файла " << filename << '\n';
            return 1;
        }
    }

    gavrilova::CommandProcessor processor(db);
    processor.run();

    return 0;
}