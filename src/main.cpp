#include <iostream>
#include "request.hpp"

int main() {
    auto r = request {
        .url = "https://discord.com/api/v8/channels/819962098058526772/messages",
        .headers = {
            "Host: discord.com",
            "Connection: close",
            "X-Super-Properties: eyJvcyI6IldpbmRvd3MiLCJicm93c2VyIjoiQ2hyb21lIiwiZGV2aWNlIjoiIiwic3lzdGVtX2xvY2FsZSI6ImVuLUdCIiwiYnJvd3Nlcl91c2VyX2FnZW50IjoiTW96aWxsYS81LjAgKFdpbmRvd3MgTlQgMTAuMDsgV2luNjQ7IHg2NCkgQXBwbGVXZWJLaXQvNTM3LjM2IChLSFRNTCwgbGlrZSBHZWNrbykgQ2hyb21lLzg5LjAuNDM4OS45MCBTYWZhcmkvNTM3LjM2IiwiYnJvd3Nlcl92ZXJzaW9uIjoiODkuMC40Mzg5LjkwIiwib3NfdmVyc2lvbiI6IjEwIiwicmVmZXJyZXIiOiJodHRwczovL2Rpc2NvcmQuY29tLyIsInJlZmVycmluZ19kb21haW4iOiJkaXNjb3JkLmNvbSIsInJlZmVycmVyX2N1cnJlbnQiOiJodHRwczovL2Rpc2NvcmQuY29tLyIsInJlZmVycmluZ19kb21haW5fY3VycmVudCI6ImRpc2NvcmQuY29tIiwicmVsZWFzZV9jaGFubmVsIjoic3RhYmxlIiwiY2xpZW50X2J1aWxkX251bWJlciI6ODI4NjYsImNsaWVudF9ldmVudF9zb3VyY2UiOm51bGx9",
            "Authorization: MzQxNTU1Njc5MTU4MzM3NTM4.YIGnDw.JdxJVSyEy24dpevNQbI-kW56guk",
            "Accept-Language: en-US",
            "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36",
            "Content-Type: application/json",
            "Accept: */*",
            "Origin: https://discord.com",
            "Sec-Fetch-Site: same-origin",
            "Sec-Fetch-Mode: cors",
            "Sec-Fetch-Dest: empty",
            "Referer: https://discord.com/channels/@me/819962098058526772",
            "Accept-Encoding: gzip, deflate"
        },
        .data = "{\"content\": \"cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum cum\"}"
    };

    r.post()
        .make_request()
        ;
}