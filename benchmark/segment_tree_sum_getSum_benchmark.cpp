#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include <vector>       // vector
#include <iterator>     // istream_iterator
// подключаем вашу структуру данных
#include "segment_tree_sum.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};
static constexpr auto kBenchmarkResultsPath = string_view{PROJECT_BENCHMARK_RESULT_DIR};
static const string kBenchmarkResultOutputFile = "segment_tree_sum_getSum_benchmark.csv";

int main(int argc, char **argv) {

  // Tip 1: входные аргументы позволяют более гибко контролировать параметры вашей программы

  // Можете передать путь до входного/выходного файла в качестве аргумента,
  // т.е. не обязательно использовать kDatasetPath и прочие константы

  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  // работа с набором данных
  const auto path = string(kDatasetPath);
  cout << "Path to the 'dataset/' folder: " << path << endl;
  const auto path_to_benchmark_result = string(kBenchmarkResultsPath) + "/" + kBenchmarkResultOutputFile;

  auto benchmark_settings_file = ifstream(path + "/benchmarkSettings.settings");

  if (!benchmark_settings_file){
    cout << "benchmark_settings_file does not exist";
    return -1;
  }

  auto benchmark_result_output = ofstream(path_to_benchmark_result);
  benchmark_result_output << "samplesCount,result" << "\n";

  string line;
  while (getline(benchmark_settings_file, line)){
    if (line == ""){
      break;
    }
    istringstream iss(line);
    vector<std::string> dataset_settings(istream_iterator<std::string>{iss},
                                         istream_iterator<std::string>());
    auto input_file = ifstream(path + "/" + dataset_settings[0]);
    int count_of_samples = stoi(dataset_settings[1]);

    int dataset[count_of_samples];

    for (int i = 0; i < count_of_samples; ++i) {
      input_file >> dataset[0];
    }

    auto segmentTreeSum = new SegmentTreeSum(dataset, count_of_samples);

    const auto time_point_before = chrono::steady_clock::now();

    // здесь находится участок кода, время которого необходимо замерить
    segmentTreeSum->getSum(0,count_of_samples-1);

    const auto time_point_after = chrono::steady_clock::now();

    const auto time_diff = time_point_after - time_point_before;
    const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    cout << "Dataset: " << dataset_settings[0] << " Time elapsed (ns): " << time_elapsed_ns << " \n";
    benchmark_result_output << dataset_settings[1] << "," << to_string(time_elapsed_ns) << "\n";
    benchmark_result_output.flush();
    input_file.close();
  }

  return 0;
}
