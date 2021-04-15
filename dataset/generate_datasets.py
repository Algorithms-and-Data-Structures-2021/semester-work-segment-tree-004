import json
import os

DATASETS_JSON = "datasets.json"
BENCHMARK_SETTINGS_FILE = "data/benchmarkSettings.settings"


class Dataset(object):
    def __init__(self, samples_count, output_path):
        self.samples_count = samples_count
        self.output_path = output_path

    def create_dataset(self):
        with open(self.output_path, 'w') as file:
            for i in range(1, self.samples_count):
                file.write('{} '.format(i))
            file.write(str(self.samples_count))


def create_datasets():
    with open("datasets.json", "r") as f:
        datasets_dict = json.load(f)

    target_folder = datasets_dict["targetFolder"]
    file_format = datasets_dict["fileFormat"]

    benchmark_settings_file = open(BENCHMARK_SETTINGS_FILE, "w")

    for dataset in datasets_dict["datasets"]:
        Dataset(dataset["samplesCount"],
                os.path.dirname(__file__) + "/" + target_folder + dataset["outputFileName"] + "." + file_format)\
            .create_dataset()
        benchmark_settings_file.write(dataset["outputFileName"] +
                                      "." + file_format + " " +
                                      str(dataset["samplesCount"]) + " " + str(dataset["numberOfPasses"]) +"\n")

    benchmark_settings_file.close()


if __name__ == "__main__":
    create_datasets()
