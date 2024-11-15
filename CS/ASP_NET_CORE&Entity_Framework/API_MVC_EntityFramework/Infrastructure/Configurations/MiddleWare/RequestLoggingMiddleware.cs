using Microsoft.AspNetCore.Http;
using System.Runtime.CompilerServices;

namespace Infrastructure.Configurations.MiddleWare
{
    public class RequestLoggingMiddleware
    {
        private readonly RequestDelegate _next;

        public RequestLoggingMiddleware(RequestDelegate next)
        {
            _next = next;
        }

        public async Task InvokeAsync(HttpContext context)
        {
            Console.WriteLine($"Request: {context.Request.Method} {context.Request.Path}");
            await _next(context);
            Console.WriteLine($"Response: {context.Response.StatusCode}");
        }
    }


}
