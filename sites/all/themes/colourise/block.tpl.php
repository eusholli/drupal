<?php
// $Id: block.tpl.php,v 1.2 2009/04/26 17:24:28 gibbozer Exp $
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
<?php if ($block->subject): ?>
  <h2 class="block-title"><?php print $block->subject ?></h2>
<?php endif;?>

  <div class="content">
    <?php print $block->content ?>
  </div>
</div>