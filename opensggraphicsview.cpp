#include "opensggraphicsview.h"

class OpenSGGraphicsView : public GraphicsView
{
public:
   OpenSGGraphicsView()
   {
      OSG::PassiveWindowPtr mPwin;
      OSG::SimpleSceneManager *mMgr;

      mMgr = new OSG::SimpleSceneManager;
      mPwin = OSG::PassiveWindow::create();
      mMgr->setWindow(mPwin);
      mMgr->setRoot(OSG::makeTorus(.5, 2, 16, 16));
      mMgr->showAll();

      scene = new OpenGLScene(mPwin, mMgr); // Instanciation de la classe qui hérite de QGraphicsScene
      setWindowTitle(tr("3D Model Viewer")); // Titre de la fenêtre
      setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers))); // On lui donne un QGLWidget pour dessiner
      setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
      setScene(scene); // On lui dit d'utiliser la scène qu'on vient de créer
      scene->setSceneRect(QRect(QPoint(0, 0), QPoint(500,500))); // On lui donne une taille
   }
};
