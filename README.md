# Center of Mass Calculator

Учебная программа на C++ (процедурный стиль, работа через `FILE*`, динамические массивы),
вычисляющая координаты центра масс для *K* точек.  
Проект полностью изолируется через Docker и одинаково работает на macOS (Apple Silicon)
и Windows (WSL или Docker Desktop).

---

## 📂 Структура проекта

```
.
├── center_of_mass.h          # Заголовок с прототипами
├── center_of_mass.cpp        # Реализация
├── main.cpp                  # Точка входа
├── build.sh                  # Сценарий сборки внутри контейнера
├── docker-compose.yml        # Container gcc:13 + volume‑маунт
├── input.txt                 # Пример входного файла
└── README.md                 # Документация
```

---

## 🔢 Формат файлов

*`input.txt`* — 4 логические строки:

```
K
x1 x2 ... xK
y1 y2 ... yK
m1 m2 ... mK
```

Разделители — пробелы, табы, запятые в любой комбинации.  
*`output.txt`* — две координаты с 6 знаками после запятой:

```
XC YC
```

---

## ⚡ Квик‑старт

### macOS (Apple Silicon)

1. Установите **Docker Desktop**.
2. В терминале перейдите в каталог проекта.
3. Соберите и запустите:

   ```bash
   docker compose run --rm cpp-dev ./build.sh
   ./center_of_mass        # появится output.txt
   ```

### Windows 10/11

> Потребуется **Docker Desktop для Windows** и включённый **WSL 2**.

1. Поставьте Docker Desktop, включите «Use WSL 2 based engine».
2. Откройте *PowerShell* или *Windows Terminal* и перейдите в папку проекта.
3. Запустите:

   ```powershell
   docker compose run --rm cpp-dev ./build.sh
   .\center_of_mass.exe   # в том же каталоге появится output.txt
   ```

*Альтернатива — MSYS2/MinGW‑w64:*  
- Установите `mingw-w64-x86_64-gcc`  
- Запустите:

  ```bash
  g++ -std=c++17 -Wall -Wextra -O2 main.cpp center_of_mass.cpp -o center_of_mass.exe
  center_of_mass.exe
  ```

---

## 🛠️ Скрипт `build.sh`

Запускается внутри контейнера (`bash`):

```bash
./build.sh
# или
docker compose run --rm cpp-dev ./build.sh
```

Он компилирует `main.cpp` + `center_of_mass.cpp` в бинарь `center_of_mass`
и сообщает о результате.

---


## 📜 Лицензия

MIT — свободно используйте и модифицируйте.
