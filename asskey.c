#include <curl/curl.h>
#include <curl/easy.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Callback function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
  CURL *curl;
  FILE *fp;
  CURLcode res;
  char *url = argv[1];
  const char *out_file = "/tmp/asskeyc.jpg";

  curl = curl_easy_init();
  if (!curl) {
    perror("Error initializing curl");
    return 1;
  }

  fp = fopen(out_file, "wb");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
            curl_easy_strerror(res));
  }

  fclose(fp);
  curl_easy_cleanup(curl);

  printf("%s", url);
  return 0;
}
