[top]
components : RequestHandler@RequestHandler Checkstock@Checkstock 
out : out 
in : ReqIn 
Link : ReqIn ReqIn@RequestHandler
Link : out@RequestHandler in@Checkstock
Link : out@Checkstock out
Link : done@Checkstock done@RequestHandler

[RequestHandler]
preparation : 00:00:10:000

[Checkstock]
distribution : Normal
mean : 4
deviation : 3


