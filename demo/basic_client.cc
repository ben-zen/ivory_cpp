#include <cpprest/filestream.h>
#include <cpprest/http_client.h>

#include <iostream>

namespace cs = concurrency::streams;
namespace whc = web::http::client;

int main(int argc, char** argv) {
  // Open a connection to Wikipedia, pull down some search results, print out a list of articles that match.
  whc::http_client client(U("https://en.wikipedia.org/"));
  std::cout << "Creating an http_client for URI: " << client.base_uri().to_string() << std::endl;
  web::uri_builder builder(U("/w/api.php"));
  builder.append_query("action", "query");
  builder.append_query("prop", "categories");
  builder.append_query("titles", "Representational state transfer");
  builder.append_query("format", "json");

  std::cout << "Making a GET request for " << builder.to_string() << std::endl;
  web::http::http_request request(web::http::methods::GET);
  request.headers().add(web::http::header_names::user_agent, "ben-zen Cpp REST SDK test");
  request.set_request_uri(builder.to_string());

  cs::container_buffer<std::string> response_body_buffer;
  auto result = client.request(request);
  result.then([response_body_buffer](web::http::http_response response){
    return response.body().read_to_end(response_body_buffer);
  }).then([response_body_buffer](size_t count){
    // Here we can actually parse the returned JSON.
    std::cout << response_body_buffer << std::endl;
  }).wait();
  return 0;
}