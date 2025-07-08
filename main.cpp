#include <pcl/io/pcd_io.h>
#include <filesystem>
#include <chrono>
#include "viz/PC_viz.h"
#include "em/EM.h"

int main(int argc, char **argv)
{
    std::filesystem::path exeDir = std::filesystem::current_path();
    std::filesystem::path folderPath = exeDir / "data" / "PCD";

    std::vector<std::string> Files;

    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".pcd")
            Files.push_back(entry.path().string());
    }

    for (const auto &file : Files)
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
        if (pcl::io::loadPCDFile<pcl::PointXYZ>(file, *cloud) == -1)
        {
            PCL_ERROR("PCD 파일을 로드할 수 없습니다: %s\n", file.c_str());
            continue;
        }

        //-------------------
        //* EM 알고리즘 실행
        //-------------------
        ExpectationMaximization gmm(2, true);
        gmm.run(cloud);
    }
    return 0;
}
