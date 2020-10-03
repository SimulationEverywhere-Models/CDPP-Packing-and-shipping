File name readme-packingAndShipping
Author Sukhvir Kaur Sahota
Date Oct.02.2017
Purpose: Describe Model simulation of order Packing and delivery
*****************************************************************************************************************************

*****************************************************************************************************************************
Atomic model: RequestHandler
Purpose: To get the new order request and handle it on FIFO basis
Describe atomic model: RequestHandler

Function:
It is an atomic model which is used to store request.It has two input ports ReqIn & Done. "ReqIn"  input ProductId, while "Done" comes from Checkstock. It has one output port out.

Test strategy:
RequestHandler.ma includes information regarding configuration and value of preparationTime.

Result:
bat: RequestHandler.bat
input: RequestHandler.ev
output: RequestHandler.out
logfile: RequestHandler.log
*****************************************************************************************************************************
Atomic model: Checkstock
Purpose:This model chack the requested order in a stock 
Describe the atomic model: Checkstock

Function:
Checkstock is an atomic model which is used to check the avilability of order in a stock.It has one input port in and two output ports out and done. "in" comes from RequestHandler. 

Result:
bat : Checkstock.bat
input: Checkstock.ev
output: Checkstock.out
logfile: Checkstock.log


*****************************************************************************************************************************
Atomic model: Packing
Purpose: Describe the atomic model: Packing

Function:
Packing is an atomic model where the products are packed and send for shipping. It has one input ports "in", comes from couple model Order and one output "out".
Test strategy:

Result:
bat: Packing.bat
input: Packing.ev
output: Packing.out
logfile: Packing.log
*****************************************************************************************************************************
Atomic model: Shipping
Purpose: Describe the atomic model: Shipping

Function:
Shipping is an atomic model where shipping of product is done. It has one input ports "in", comes from Packing model and one output "out".

Result:
bat: Shipping.bat
input: Shipping.ev
output: Shipping.out
logfile: Shipping.log
*****************************************************************************************************************************
Atomic model: Delivery
Purpose: Describe the atomic model: Delivery

Function:
Delivery is an atomic model which describe the time taken for delivery. It has one input ports "in", comes from Packing model and one output "closeOrder".

Result:
bat: Delivery.bat
input: Delivery.ev
output: Delivery.out
logfile: Delivery.log
*****************************************************************************************************************************
Coupled model: Order
Purpose: Describe the coupled model: Order

Function:
Order is a coupled model including RequestHandler and Checkstock two atomic models. It has one input port ReqIn and one output port out.

Result:
bat: Link1.bat
input: Link1.ev
output: Link1.out
logfile: Link1.log
*****************************************************************************************************************************
Coupled model: Vendor
Purpose:this model basically check the linking between Packing and Shipping atomic model.
Describe the coupled model: Vendor

Function:
Vendor is a coupled model including Packing and Shipping two atomic models. It has one input port in and one output port closeOrder.

*****************************************************************************************************************************
Top-level model: packingAndShipping
Function:
top-level is a model including Order, Vendor and delivery with  totally five atomic models. It has one input port "ReqIn" and one output port closeOrder.


Test 1 
Result:
Bat: packingAndShipping.bat
output: packingAndShipping.out
logfile: packingAndShipping.log

Test 2
Result:
Bat: simulation1.bat
output: packingAndShipping1.out
logfile: packingAndShipping1.log

