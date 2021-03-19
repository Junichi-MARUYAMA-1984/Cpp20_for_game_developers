#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() {
    // カレントディレクトリを取得
    cout << fs::current_path() << endl;

    // ファイルが存在するか否かを確認
    if (fs::exists("test.txt")) {
        fs::copy("test.txt", "test2.txt"); // ファイルをコピー
    }
    // ファイルを読み込む前に、ファイルのサイズを取得
    cout << fs::file_size("save.dat") << endl;

    // フォルダを作成
    fs::create_directories("aaa/bbb/ccc");

    // カレントディレクトリに含まれる全ファイルを出力
    for (const auto& entry : fs::recursive_directory_iterator("./")) {
        cout << entry.path() << endl;
    }
}