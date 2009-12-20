<?php
// $Id: node.tpl.php,v 1.3 2009/04/26 17:24:28 gibbozer Exp $
?><div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <?php if (!$page): ?>
    <h2 class="title">
      <a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <div class="post-info">

    <?php print $picture ?>

    <?php if ($submitted): ?>
      <span class="submitted"><?php print $submitted ?></span>
    <?php endif; ?>

    <?php if ($terms): ?>
      <div class="terms"> <?php print t('Related Terms') ?> : <?php print $terms ?></div>
    <?php endif; ?>

  </div>

  <div class="content">
    <?php print $content ?>
  </div>

  <?php if ($links): ?>
    <div class="node-links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

</div>