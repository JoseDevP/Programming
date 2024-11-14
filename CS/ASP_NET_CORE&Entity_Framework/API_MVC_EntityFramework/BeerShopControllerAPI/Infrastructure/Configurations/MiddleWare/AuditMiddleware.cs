namespace BeerShop.Infrastructure.Configurations.MiddleWare
{
    public class AuditMiddleware
    {
        private readonly RequestDelegate _next;

        public AuditMiddleware(RequestDelegate next)
        {
            _next = next;
        }

        public async Task InvokeAsync(HttpContext context)
        {
            Console.WriteLine($"Request: {context.Request.Method} {context.Request.Path} at {DateTime.UtcNow}");
            await _next(context);
            Console.WriteLine($"Response: {context.Response.StatusCode} at {DateTime.UtcNow}");
        }
    }

}
