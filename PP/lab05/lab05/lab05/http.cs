using System;
using System.Collections.Generic;
using System.Text;

public class HttpRequest
{
    public string Method { get; set; }
    public string Uri { get; set; }
    public string Version { get; set; } = "HTTP/1.1";
    public Dictionary<string, string> Headers { get; set; } = new Dictionary<string, string>();
    public string Body { get; set; }

    public HttpRequest(string method, string uri)
    {
        Method = method;
        Uri = uri;
    }

    public string BuildRequest()
    {
        StringBuilder requestBuilder = new StringBuilder();

        requestBuilder.AppendLine($"{Method} {Uri} {Version}");

        foreach (var header in Headers)
        {
            requestBuilder.AppendLine($"{header.Key}: {header.Value}");
        }

        requestBuilder.AppendLine();

        if (!string.IsNullOrEmpty(Body))
        {
            requestBuilder.AppendLine(Body);
        }

        return requestBuilder.ToString();
    }
}

class Program
{
    static void Main()
    {
        var request = new HttpRequest("GET", "/index.html");
        request.Headers.Add("Host", "www.example.com");
        request.Headers.Add("User-Agent", "MyClient/1.0");
        request.Headers.Add("Accept", "text/html");

        string httpMessage = request.BuildRequest();
        Console.WriteLine(httpMessage);
    }
}