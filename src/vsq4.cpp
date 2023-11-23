#include"vsq4.h"

void VsqxNoteHelper::Vsq4::ReadVsqx(std::string filePath) {
    // 加载文件
    pugi::xml_document vsqx;
    pugi::xml_parse_result result = vsqx.load_file(filePath.c_str());
    std::cout << "LoadResult: " << result.description() << std::endl;
}