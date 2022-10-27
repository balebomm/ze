# MIDDLEWARE
Middleware functions are functions that have access to the request object (req), the response object (res), and the next middleware function in the application’s request-response cycle. The next middleware function is commonly denoted by a variable named next.

### Middleware functions can perform the following tasks:

* Execute any code.
* Make changes to the request and the response objects.
* End the request-response cycle.
* Call the next middleware function in the stack.
Execute any code.
Make changes to the request and the response objects.
End the request-response cycle.
Call the next middleware function in the stack.

If the current middleware function does not end the request-response cycle, it must call next() to pass control to the next middleware function. Otherwise, the request will be left hanging.

```
app.use( 
  function(req, res, next)
  {
    if(['normal','vip'].includes(res.params.id))
    {
      req.face = 'ABC'
      return next();
    }
    res.status(403).json({message:"access denied"})
  },
  function(res, req, next)
  {
    res.json({
      message:"Successful",
      face: "req.face"
    })
  }
)
  
```
