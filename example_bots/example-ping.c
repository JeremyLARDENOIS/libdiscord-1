//
// Created by danielxing.6 on 11/21/2017.
//

/*
 * ping bot example
 *
 * potential response times to measure:
 *
 *      latency between sending a HTTP request and receiving a response for endpoints such as:
 *          GET /gateway
 *          DELETE [message]
 *          POST [message]
 *          GET [messages]
 *
 *      latency between a HTTP request and it's corresponding gateway dispatch, such as:
 *          POST [message] -> G RECIEVE DISPATCH new [message]
 *
 *      latency between a sent gateway payload and a response from the gateway
 *          G SEND STATUS_UPDATE -> G RECIEVE DISPATCH new [status]
 *          G SEND HEARTBEAT ->
 */
#include <libdiscord.h>

int main(int argc, char *argv[]) {
    ld_set_logging_level(31);

    struct ld_rest_request *request;
    request = ld_rest_init_request();

    struct ld_rest_response *response;
    response = ld_rest_init_response();

    request->base_url = "https://google.com";
    request->endpoint = "/";
    request->verb = LD_REST_VERB_GET;
    request->body = NULL;
    request->body_size = 0;

    ld_rest_send_blocking_request(request, response);

    ld_info("recieved data from %s%s, (%d) bytes long (%d):\n%.*s", request->base_url, request->endpoint, response->body_length, response->http_status, response->body_length, response->body);

//    request = ld_get_gateway();
//    ld_rest_send_blocking_request(request, response);
//    ld_info("recieved data from %s%s, (%d) bytes long (%d):\n%.*s", request->base_url, request->endpoint, response->body_length, response->http_status, response->body_length, response->body);

    return 0;
}