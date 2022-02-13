# Modifying Home Depot skeleton

Purchase the "Home Accents Holiday 5 ft. Poseable Skeleton with LED Illumination". Might be available on web site in a set of 6.

Here's how to modify the skeleton and add the servo parts.

## Unscrew screws on the head.

Remove 6 screws from the head. **Save these screws for reassembly!**

Unscrew the screws holding the head to the spine and remove the head. 
These screws will not be needed again.

## Modify battery case

Remove batteries.

Remove Try Me button.

Cut the wires to the LEDs as close as possible to the battery case.

Remove the power switch.

Dremel out the power switch hole so that CAT 5 cable can fit through.

Rescrew battery case screws on.

# Mounting the neck servo

## Modifying Neck

With Dremel, cut off the neck part attached to the head.

With Dremel, cut off one level of neck part attached to the body. There should still be at 
least an inch of hollow tube above the large hole through the neck.

With Dremel sanding tool, clean out the inside of the neck just below the hole.

## Inserting neck servo mount.

Insider the neck servo mount flush down with the battery case back. Sand that flat with the
Dremel if needed. Mark hole positions with the neck mount in place, remove the mount, and use
Dremel to put holes in battery case with 5/64 inch drill bit. 

Insert the mount and screw down with two 1/2 inch #4 sheet metal screws.

## Attach plastic cylinder to servo

Using four very small self-tapping screws (M1.7/5), attach the black plastic cylinder to a round servo
attachment.

Using an Arduino, center the servo at the 90 degree position. At this position the skull should
face forward. 

Attach the servo attachment/cylinder combo to the servo using the main central screw, assuring that
the screw hole is correctly oriented so the skull will face forward when attached.

## Place servo in the mount

Slide the servo into the mount all the way, then attach the top piece using two 1/2 inch #4 sheet metal screws.

# Mounting the jaw servo

## Modifying jaw 

Unscrew the jaw from the white jaw crossbeam. **Save screws!**

Turn the white crossbeam around.

Rescrew the jaw to the white crossbeam so that when the jaw is fully open, the white slot
that sticks out from the crossbeam just touches the inside of the skull in the down position. 
Tighten the screws fairly tight so that it doesn't rotate.

## Inserting Jaw servo mount

Insert the servo mount into the skull. Make sure everything is flat and tight, and the that long 
piece that goes to the back of the head goes between two screw pillars. The crossbeam should be tight
against plastic under the top of the jaw.

Using the Dremel 3/32" drill bit (different than before!) drill two holes through the plastic under the 
jaw into the black plastic of the servo mount.

Screw in two 1/2 inch #4 sheet metal screws to secure the mount.

## Attach servo horn to the servo.

Using four very small (M1.7/5) self-tapping screws, attach the servo horn to the *back* of the round servo attachment.
The servo horn should be closer to the body of the servo than that the servo attached itself when mounted; the
geared hole goes through the hole on the servo horn.

Using an Arduino, center the servo at the 90 degree position. 

Attach the servo horn combination onto the servo with the main central screw. The servo horn should point 
directly away from the servo. This will require trying out 4 different positions on the round plastic connector,
because of the different positions of the gearing.

Careful slide the pin on the servo horn into the slot on the white crossbeam, and then slot the servo into the 
mount. Push all the way down.

Attach the top piece using two 1/2 inch #4 sheet metal screws.

# Solder wires and connector

## 5-wire socket and jaw servo/eyes

Solder 180 Ohm resistor (shorten the ends) to the end of the red eye wire. 

Connect the 5-socket and connector together. Solder **and heat shrink** the following wires to the socket connector (the
part without wires)

* Connector wire color -> Servo/eyes wire
* Green -> Servo Brown wire
* White -> Servo Red wire
* Yellow -> Red eye wire with resistor (use long piece of heat shrink to cover whole resistor)
* Black -> Black eye wire

## CAT-5 to Wires

Get a Cat-5 socket connector. Connect six colored wires as follows, using the "A" wiring standard.

* CAT 5 color -> Wire Color
* Brown -> Green
* Brown Striped -> White
* Green -> Blue
* Orange -> Red
* Blue -> Black
* Blue Stripe -> Yellow

## Neck servo and 5 wire connector

Twist together and solder the Neck Servo Brown wire and Green wire from the 5-wire connector (wires running same way)

Twist together and solder the Neck Servo Red wire and the White wire from the 5-wire connector (wires running same way)

Solder **and heat shrink** wires running from the CAT-5 connector and the wires from the 5-wire connector together as follows:

* Wire color running from Cat-5 connect -> 5-Wire Connector wire color
* Green -> Green connector wire and Neck Servo Brown
* White -> White connector wire and Neck Servo Red
* Red  -> Red connector wire
* Yellow -> Yellow connector wire
* Black -> Black connector wire
* Blue -> Neck Servo Orange


# Assemble

Screw the head together again using the saved screws.

Attach the black plastic neck into the spine, and attach using 1/4 inch, 1 1/4" long bolt and nut. Tighten nut.


# Servo ranges

Jaw servo, in degrees, using Arduino servo library: 102 = full open, 60 = full closed.  Do not go beyond these ranges. 
Getting this right requires that 90 is servo horn directly forward. May require calibrating each head specifically, but
this should get you close.

Neck servo: 90 is forward, 0 and 180 are full to each side.
