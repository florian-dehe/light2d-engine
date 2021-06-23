#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

namespace light2d {
    /**
     * @brief Namespace for utilitaries classes in Light2D.
     */
    namespace utils {
        /**
         * @brief Utilitary class to read files.
         */
        class FileReader {
        public:
            /**
             * @brief Reads a file from filepath.
             * @param filepath The file to read.
             * @return The content (as text) of the file.
             */
            static std::string readFile(std::string filepath);
        };
    }
}

#endif /* FILEREADER_H */

