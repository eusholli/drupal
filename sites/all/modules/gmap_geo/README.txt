----------------
 Using Gmap_geo
----------------

As of July 1, 2009, gmap_geo is being kept approximately in sync (within a week)
of Geo HEAD.

Gmap_geo requires a patch to Geo to fix Views-related behavior:
http://drupal.org/node/505572

Gmap_geo requires the latest -dev version of GMap:
http://drupal.org/node/95786

----------
 Features
----------
Gmap_geo adds functionality to Geo CCK fields; these features are available
when you edit a content type.

* When adding a "Geospatial data" CCK field to a node type, among the widget
options you will now see "GMap picker" along with the default "Direct Text
Entry" and "Latitude / Longitude".

* In the "Display fields" tab you see when editing a content type, fields of
type "Geospatial data" and "Geospatial data reference" will have an additional
"GMap" formatter available. For fields that use the GMap picker widget for data
entry, this map will be formatted according to the macro in the field settings;
otherwise, it will use GMap's default settings. The map will autozoom to show
all the points (if the field has multiple points), but there is currently no
autozoom for shapes and lines.

Gmap_geo provides a Views style plugin to display Geo fields on a GMap. This
function is available when you are creating and editing views. This is currently
very limited--you may display points, lines, and polygons from Geo, but only
with default markers and line/fill styles.


-----------
 Internals
-----------

Lines and polygons are presented on GMaps as "encoded polylines". Encoded
polylines are a Google Maps data structure that compresses line and polygon data
and adds a zoom level to each point; this allows the map to display shapes more
efficiently when zoomed out, and to reveal more detail as you zoom in.
Functionality GMap's "gmap_polyutil.inc" file takes line/polygon data,
simplifies it, and encodes it for Google Maps.

--------
Gmap_geo is developed by Rebecca White (bec). This work has been supported by
the Chicago Technology Cooperative and MoveSmart.org.
