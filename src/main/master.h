#pragma once

#include "file_handling.h"
#include "settings.h"
#include "output.h"
#include "computations.h"
#include "read_storage.h"
#include "../mapping/mapping.h"

#include <thread>


class Master {

    public:

        hash_index referenceGenome;

        Output output;

        const Settings settings;

        Master(std::vector<std::string> settingsVector, bool m);

        bool mem;

        // Loads small read files in memory, compares original/corrected/reference sequences and increments counters accordingly
        void processOneBatch(uint n);

        // Calculate the gain obtained after correction, using the number of True Positives, False Positives and False Negatives
        void evaluation();

};
