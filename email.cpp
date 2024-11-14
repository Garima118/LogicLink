#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

void send_email() {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = NULL;

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // SMTP Server and authentication
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "mohdfarhan2004.oppo@gmail.com");

        // Add recipients
        recipients = curl_slist_append(recipients, "mi719033@gmail.com");
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set the message body
        const char *message = "Subject: Test Email\n\nThis is a test email sent using libcurl in C++.\n";
        curl_easy_setopt(curl, CURLOPT_READDATA, message);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Enable authentication (if needed)
        curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "#Fari786");

        // Enable SSL/TLS encryption
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURL_USESSL_ALL);

        // Send the email
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "Failed to send email: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "Email sent successfully!" << endl;
        }

        // Clean up
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    // Clean up global state
    curl_global_cleanup();
}

int main() {
    send_email();
    return 0;
}
