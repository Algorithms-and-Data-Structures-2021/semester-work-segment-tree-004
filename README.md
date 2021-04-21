# Дерево отрезков (Segment tree)

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-segment-tree-004/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

### Описание семестрового проекта:

##### Название структуры данных 

​	Дерево отрезков (Segment tree)

##### Что она из себя представляет?

​	Дерево отрезков — это структура данных, которая позволяет за асимптотику O(logn) реализовать любые операции, определяемые на множестве, на котором данная операция ассоциативна.

 ##### Где и как она используется?



##### Какие операции над ней можно выполнять?

​	Любые ассоциативные функции на отрезке, в нашей реализации - нахождение суммы на отрезке и нахождение минимума на отрезке

##### Какова теоретическая сложность операций?

​	*Построение дерева* - **O(N)**

​	*Вычисление любой ассоциативной функции на отрезке* - **O(logN)**

​	*Замена элемента по индексу* - **O(logN)**

##### Структура

​	Структура представляет собой дерево, листьями которого являются элементы исходного массива. Другие вершины этого дерева имеют по 22 ребенка и содержат результат операции от своих детей (например минимум или сумму).



_Краткое описание семестрового проекта. Следует отразить информацию по следующим пунктам:_

- _Какая структура данных реализуется?_
- _Что она из себя представляет (сбалансированное дерево, линейный список и пр.)?_
- _Где и как она используется (приложения)?_
- _Какие операции над ней можно выполнять (поиск, удаление, добавление, вставка и пр.)?_
- _Какова теоретическая сложность операций (поиск за `O(log(n))`, вставка за `O(n^2)` и т.д.)?_
- _Какая-то другая справочная информация о проекте._
- _Структура_

## Команда "zxc"

| Фамилия Имя     | Вклад (%) | Прозвище |
| :-------------- | --------: | -------: |
| Ибрагимов Айдар |        50 |      _x_ |
| Булатов Дмитрий |        50 |       _x |

**Девиз команды**
> _Наши цели ясны. Задачи определены. За работу, товарищи!_

## Структура проекта

_Описание основных частей семестрового проекта._

**Пример**. Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
  - [`benchmark/benchmark-visualization`](benchmark/benchmark-visualization) - визуализация результатов контрольных тестов
  - [`benchmark/benchmark-results`](benchmark/benchmark-results)
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

_В этом разделе задаются основные требования к программному и аппаратному обеспечению для успешной работы с проектом._

**Пример**. Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Пример (Windows)

#### Сборка проекта

_Опишите процесс сборки проекта._

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template.git
```
Создайте виртуальное окружение python:
```shell
python3 -m venv venv
```
Активируйте виртуальное окружение :
```shell
venv\Scripts\activate.bat
```
Загрузите зависимости проекта с помощью пакетного менеджера pip :
```shell
pip install -r requirements.txt
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-segment-tree-004

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```



### Генерация тестовых данных

Наши реализации дерева отрезков (дерево отрезков для суммы и дерево отрезков для минимума) работают с целыми числами. Для удобства тестирования, было решено генерировать числа в диапазоне от 1 до 1000 и хранить в файле через пробел.

Генерация данных:

```shell
# переход в папку генерации набора данных
cd dataset
```

Скрипт генерирует наборы данных описанные в файле [`dataset`](dataset)/[`datasetsConfig.json`](datasetsConfig.json)

Вы можете использовать **готовую конфигурацию** или написать собственную:

```json
{
  "folder": "data/", 		// название папки для генерации datasetPackages (не изменяйте)
  "fileFormat": "dataset", 	// формат файла набора данных	(не изменяйте)
  "datasetPackages": [ 		// спискок пакетов наборов данных
    {
      "targetFolder": "buildTree/",		// папка пакета набора данных
      "datasets":[						// список наборов данных
         {
          	"samplesCount": 10000,					// количество данных в наборе
          	"outputFileName": "dataset_of_10000",	// название файла набора данных
          	"numberOfPasses": 100					// количество проходов (информация для бенчмарка)
         },
      ]
	}
  ]
}
```

Запустите скрипт генерации данных:

```shell
python generate_datasets.py
```
```
Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):
```

**Примечание**. Для запуска контрольных тестов, необходимо сгенерировать 4 пакета наборов данных:

```shell
dataset/data/
  buildTree/
    datset_of_500.dataset
    ...
    benchmarkSettings.settings
  getMin/
    datset_of_500.dataset
    ...
    benchmarkSettings.settings
  getSum/
  	datset_of_500.dataset
    ...
    benchmarkSettings.settings
  update/
  	datset_of_500.dataset
    ...
    benchmarkSettings.settings
```



### Контрольные тесты (benchmarks)

**Примечание**. Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать наборы тестовых данных. Наборы данных находятся в папке семестровой работы на [Google Drive](https://drive.google.com/drive/folders/1AJ7OVSdZCuwLSW08ErgsgJfPMe2kk5rd?usp=sharing).

##### Список контрольных тестов

| Название                                         | Описание                                | Метрики |
| :----------------------------------------------- | --------------------------------------- | :------ |
| `segment_tree_sum_buildTree_benchmark`           | построение дерева отрезков для суммы    | _время_ |
| `segment_tree_sum_getSum_wholeSegment_benchmark` | получение суммы всего отрезка           | _время_ |
| `segment_tree_sum_getSum_average_benchmark`      | получение суммы случайного отрезка      | время   |
| `segment_tree_sum_update_benchmark`              | обновление элемента по индексу          | _время_ |
| `segment_tree_min_buildTree_benchmark`           | построение дерева отрезков для минимума | _время_ |
| `segment_tree_min_getMin_wholeSegment_benchmark` | получение минимума всего отрезка        | _время_ |
| `segment_tree_min_getMin_average_benchmark`      | получение минимума случайного отрезка   | время   |
| `segment_tree_min_update_benchmark`              | обновление элемента по индексу          | _время_ |



В каждом сгенерированном пакете наборов данных лежит файл benchmarkSettings.settings, в котором содержится информация о наборах для контрольных тестов. Поэтому для замера результатов на всех наборах, достаточно просто запустить контрольный тест.

##### Примеры запуска

```shell
./*имя_бенчмарка*
```

Построение дерева отрезков для суммы (найти среднее значение для каждого из наборов данных):

```
./segment_tree_sum_buildTree_benchmark
```

Результаты контрольных тестов сохраняются в папке [`benchmark/benchmark-visualization/benchmark-results/`](benchmark/benchmark-visualization/benchmark-results/)



 ### Визуализация результатов контрольных тестов

Создание графиков на основе результатов контрольных тестов

```shell
# переход в папку визуализации результотов контрольных тестов
cd benchmark/benchmark-visualization
```

**Примечание**. Для создания графиков необходимо предварительно получить результаты контрольных тестов в .csv формате

Скрипт создаёт графики на основе json-конфигурации в файле [`benchmark/benchmark-visualization/benchmarkGraphs.json`](benchmark/benchmark-visualization/benchmarkGraphs.json) Вы можете создавать собственные графики, дописывая их в список "benchmarkGraphs":

```json
{
  "benchmarkGraphs": [ // список графов
    {
      "title": "sum of segment(whole segment): segment tree - linear impl", // оглавление графа
      "sources":[ // источники данных для построения графов, список должен содержать один или два источника 
        "linear_getSum_benchmark.csv",
        "segment_tree_sum_getSum_wholeSegment_benchmark.csv"
      ],
      "outputFile": "sum_of_segment_segment_tree_vs_linear_impl(whole segment).png" // имя выходного файла
    }
  ]
}
```

<details>
    <summary>Результат из конфигурации выше </summary>
    <img src="benchmark/benchmark-visualization/benchmark-graphs/sum_of_segment_segment_tree_vs_linear_impl(whole segment).png" alt="graph"/>
</details>

Создайте графики, описанные в конфигурационном файле

```shell
# запуск скрипта для создания графиков
python create_benchmark_graphs.py
```

Созданные графики будут лежать в папке [`benchmark/benchmark-visualization/benchmark-graphs`](benchmark/benchmark-visualization/benchmark-graphs)

## Источники

_Список использованных при реализации структуры данных источников._

[Дерево отрезков. Построение — Викиконспекты (ifmo.ru)](https://neerc.ifmo.ru/wiki/index.php?title=Дерево_отрезков._Построение)

[Дерево отрезков — Википедия (wikipedia.org)](https://ru.wikipedia.org/wiki/Дерево_отрезков)

[Дерево отрезков | brestprog](https://brestprog.by/topics/segmenttree/)

_**Это не плагиат, это уважение чужого труда и помощь своим сокурсникам более подробно разобраться в теме.**_