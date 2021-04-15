import matplotlib.pyplot as plt
import os

BENCHMARK_RESULTS_PATH = "./benchmark-results"


class BenchmarkResult(object):
    def __init__(self, name: str):
        self.samples_count_list = []
        self.time_list = []
        self.name = name

    def add_result(self, samples_count:int, time:float):
        self.samples_count_list.append(samples_count)
        self.time_list.append(time)

    def __repr__(self):
        return "BenchmarkResult(name=%s)" % self.name


def read_benchmark_results():
    benchmark_csv_results = []
    # csv benchmark result open
    for root, dirs, files in os.walk(BENCHMARK_RESULTS_PATH):
        for file in files:
            benchmark_csv_results.append(open(BENCHMARK_RESULTS_PATH + "/" + file, "r"))

    benchmark_results = []

    for benchmark_csv_result in benchmark_csv_results:
        benchmark_result = BenchmarkResult(benchmark_csv_result.name)

        benchmark_csv_result.readline()
        for line in benchmark_csv_result:
            samples_count = int(line.split(",")[0])
            time = float(line.split(",")[1])
            benchmark_result.add_result(samples_count, time)

        benchmark_results.append(benchmark_result)

    # closing files
    for benchmark_result in benchmark_csv_results:
        benchmark_result.close()

    return benchmark_results

def create_graphs():
    benchmark_results = read_benchmark_results()

    plt.plot(benchmark_results[0].samples_count_list,
             benchmark_results[0].time_list)
    plt.plot(benchmark_results[2].samples_count_list,
             benchmark_results[2].time_list)
    plt.title(benchmark_results[0].name + " " + benchmark_results[2].name)

    plt.ylabel("time, ns", size=14, color='green')
    plt.xlabel("samples amount", size=14,color='green')

    plt.show()

if __name__ == "__main__":
    create_graphs()
