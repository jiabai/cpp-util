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
      char c1 = URL[++i];
      char c0 = URL[++i];
      int num = 0;
      num += hexChar2dec(c1) * 16 + hexChar2dec(c0);
      result += char(num);
    }
  }
  return result;
}
