namespace zen::activitypub::activity_vocabulary {
  class object {
    /*
     * Supports the following:
     * attachment
     * attributedTo
     * audience
     * content
     * context
     * name
     * endTime
     * generator
     * icon
     * image
     * inReplyTo
     * location
     * preview
     * published
     * replies
     * startTime
     * summary
     * tag
     * updated
     * url
     * to
     * bto
     * cc
     * bcc
     * mediaType
     * duration
     */
  };

  class link {
    /**
     * Supports the following:
     * href
     * rel
     * mediaType
     * name
     * hreflang
     * height
     * width
     * preview
     */
  };

  class activity : public object {
    /**
     * Supports object as well as the following:
     * actor
     * object
     * target
     * result
     * origin
     * instrument
     */
  };

  // Intransitive activity ... not sure how to handle this one.

  class collection : public object {
    /**
     * Supports object as well as the following:
     * total_items
     * current
     * first
     * last
     * items
     */
  };

  class ordered_collection : public collection {
    /**
     * Supports collection, but members are strictly ordered.
     */
  };

  class collection_page : public collection {
    /**
     * Extends collection with the following:
     * part_of
     * next
     * prev
     */
  };

  class ordered_collection_page : public ordered_collection, public collection_page {
    /**
     * Extends both ordered_collection and collection_page:
     * start_index
     */
  };
};