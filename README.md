[![Build Status](https://travis-ci.org/SimonRussia/HW_Explorer_03.svg?branch=master)](https://travis-ci.org/SimonRussia/HW_Explorer_03) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](/LICENSE)
## Проект Explorer (III этап)

### Соответствие порядкового номера и комбинации:
- Порядковый номер: **20**
- Двоичное представление: **1 0 1 0 0**
- Комбинация: **0, 0, 1, 1**


## Задание
- [X] Добавить обработку множественного количества путей.
- [X] Вывод информации делегировать планировщику.
- [X] Передачу задач планировщику обеспечить через **std::packaged_task**.
- [X] Добавить тесты.
- [X] Обеспечить подключение **Boost** и **Catch** через пакетный менеджер **Hunter**.



## Пример
Для комбинации **1, 0, 1, 0**
```
$ ./explorer file.dat
path:	 /home/user/file.dat
size:	 2258 Kb
date:	 10/17/2017 8:43
```
