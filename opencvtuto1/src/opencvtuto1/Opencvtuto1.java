/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package opencvtuto1;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

/**
 *
 * @author usuario
 */
public class Opencvtuto1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        System.out.println("hola mundo opencv version" + Core.VERSION);
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        Mat m = Mat.eye(8, 8, CvType.CV_8UC1);
        System.out.println("m=" + m.dump());

    }

}
