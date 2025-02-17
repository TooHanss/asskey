#include <curl/curl.h>
#include <curl/easy.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// TODO: implement resizing and liminosity calculation
// TODO: Don't just have one big ol main func.
//  Callback function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  return fwrite(ptr, size, nmemb, stream);
}

int main(int argc, char *argv[]) {
  // Here we are defining the type of these variables with a type alias.
  // They do not yet have a value.
  CURL *curl;
  FILE *fp;
  CURLcode res;
  char *url = argv[1];
  const char *out_file = "/tmp/asskeyc.jpg";

  // Initialize the curl object so we can use it.
  curl = curl_easy_init();
  if (!curl) {
    perror("Error initializing curl");
    return 1;
  }

  // Here I suppose we could also do FILE *fp = fopen()
  // wb stands for write binary.
  fp = fopen(out_file, "wb");
  if (!fp) {
    perror("Error opening file");
    return 1;
  }

  // Here we are setting the options for our initialized curl object.
  // CURLOPT_URL defines the URL
  // CURLOPT_WRITEFUNCTION determines the function that will be called back when
  // we write CURLOPT_WRITEDATA determines the output file.
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

  // Perform the curl operation and store the result.
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
