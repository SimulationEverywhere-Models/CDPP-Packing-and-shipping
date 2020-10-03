[top]
components : Delivery@DeliveryType Order Vendor 
out : closeOrder 
in : ReqIn 
Link : ReqIn ReqIn@Order
Link : out@Order in@Vendor
Link : out@Vendor in@Delivery
Link : closeOrder@Delivery closeOrder

[Delivery]
preparation : 00:00:10:000

[Order]
components : RequestHandler@RequestHandler Checkstock@Checkstock 
out : out 
in : ReqIn 
Link : ReqIn ReqIn@RequestHandler
Link : out@Checkstock out
Link : out@RequestHandler in@Checkstock
Link : done@Checkstock done@RequestHandler

[RequestHandler]
preparation : 00:00:10:000

[Checkstock]
distribution : Normal
mean : 4
deviation : 3


[Vendor]
components : Packing@Packing Shipping@Shipping 
out : out 
in : in 
Link : in in@Packing
Link : out@Shipping out
Link : out@Packing in@Shipping

[Packing]
distribution : Normal
mean : 2
deviation : 1

[Shipping]
distribution : Normal
mean : 2
deviation : 1



