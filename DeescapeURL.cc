#include <string>
using namespace std;

short int hexChar2dec(char c) {
  if ( '0'<=c && c<='9' ) {
    return short(c-'0');
  } else if ( 'a'<=c && c<='f' ) {
    return ( short(c-'a') + 10 );
  } else if ( 'A'<=c && c<='F' ) {
    return ( short(c-'A') + 10 );
  } else {
    return -1;
  }
}

string DeescapeURL(const string &URL) {
  string result = "";
  for (int32_t i=0; i<URL.size(); i++) {
    char c = URL[i];
    if ( c != '%' ) {
      result += c;
    } else {
      // 检查是否超出字符串边界
      if (i + 2 >= URL.size()) {
        // 可以记录错误或者跳过转义序列
        continue; // 或者 break; 或者其他错误处理逻辑
      }
      char c1 = URL[++i];
      char c0 = URL[++i];
      int high = hexChar2dec(c1);
      int low = hexChar2dec(c0);
      // 检查是否是有效的十六进制转义字符
      if (high != -1 && low != -1) {
        result += char(high * 16 + low);
      } else {
        result += c;
      }
    }
  }
  return result;
}
