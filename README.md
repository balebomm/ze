## NOTE:
GET: server -> client

POST: client -> server

PUT,PATCH: update data

DELETE: delete data
## FORMAT CODE:
```
npm i prettier lint-staged husky --save-dev

```
# INSTALL MONGOOSE:
Mongoose is a MongoDB object modeling tool designed to work in an asynchronous environment. Mongoose supports both promises and callbacks.
```
npm install mongoose
```

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
ok
